// Modern Algorithm Collection Website
// Clean, minimal, and interactive design

const SUPPORTED_EXT_MAP = {
  ".js": { langId: "javascript", label: "JavaScript" },
  ".c": { langId: "c", label: "C" },
  ".cpp": { langId: "cpp", label: "C++" },
  ".go": { langId: "go", label: "Go" },
  ".java": { langId: "java", label: "Java" },
  ".py": { langId: "python", label: "Python" },
  ".rs": { langId: "rust", label: "Rust" }
};

const state = {
  algorithms: [],
  filtered: [],
  selected: null,
  activeLang: null
};

const els = {
  grid: document.getElementById('algorithmsGrid'),
  search: document.getElementById('searchInput'),
  searchCount: document.getElementById('searchCount'),
  totalAlgorithms: document.getElementById('totalAlgorithms'),
  viewer: document.getElementById('codeViewer'),
  viewerTitle: document.getElementById('codeViewerTitle'),
  viewerSubtitle: document.getElementById('codeViewerSubtitle'),
  closeViewer: document.getElementById('closeCodeViewer'),
  overlay: document.getElementById('overlay'),
  tabs: document.getElementById('languageTabs'),
  codeDisplay: document.getElementById('codeDisplay'),
  codeText: document.getElementById('codeText'),
  copyBtn: document.getElementById('copyBtn')
};

async function loadManifest() {
  try {
    const res = await fetch('./algorithms.json', { cache: 'no-store' });
    if (!res.ok) throw new Error('Failed to load manifest');
    const data = await res.json();

    state.algorithms = (Array.isArray(data) ? data : []).map(normalizeAlgo);
    state.filtered = state.algorithms;

    updateStats();
    renderGrid();

  } catch (err) {
    console.error(err);
    els.grid.innerHTML = `
      <div class="algorithm-card">
        <div class="algorithm-title">Manifest not found</div>
        <p class="algorithm-description">Run the generator script to create algorithms.json</p>
      </div>
    `;
  }
}

function normalizeAlgo(a) {
  const langs = a.languages || {};
  const filtered = {};

  Object.keys(langs).forEach(k => {
    const files = (langs[k] || []).filter(Boolean);
    if (files.length > 0) filtered[k] = files;
  });

  return {
    name: a.name || 'Untitled',
    slug: a.slug || (a.name || '').toLowerCase().replace(/[^a-z0-9]+/g, '-').replace(/^-+|-+$/g, ''),
    description: a.description || '',
    languages: filtered
  };
}

function updateStats() {
  els.totalAlgorithms.textContent = state.algorithms.length;
}

function updateSearchCount() {
  const count = state.filtered.length;
  if (els.search.value.trim()) {
    els.searchCount.textContent = `${count} result${count !== 1 ? 's' : ''}`;
  } else {
    els.searchCount.textContent = '';
  }
}

function renderGrid() {
  const q = (els.search.value || '').trim().toLowerCase();
  state.filtered = state.algorithms.filter(a =>
    a.name.toLowerCase().includes(q) ||
    a.description.toLowerCase().includes(q)
  );

  updateSearchCount();

  if (state.filtered.length === 0) {
    els.grid.innerHTML = `
      <div class="algorithm-card">
        <div class="algorithm-title">No algorithms found</div>
        <p class="algorithm-description">Try adjusting your search terms</p>
      </div>
    `;
    return;
  }

  els.grid.innerHTML = state.filtered.map((a, index) => {
    const langKeys = Object.keys(a.languages);
    const badges = langKeys
      .map(ext => `<span class="language-badge">${SUPPORTED_EXT_MAP[ext]?.label || ext.replace('.', '').toUpperCase()}</span>`)
      .join('');

    const desc = a.description && a.description !== a.name
      ? `<p class="algorithm-description">${escapeHtml(a.description)}</p>`
      : '';

    return `
      <div class="algorithm-card" data-slug="${a.slug}" style="animation-delay: ${index * 0.05}s">
        <h3 class="algorithm-title">${escapeHtml(a.name)}</h3>
        ${desc}
        <div class="language-badges">${badges}</div>
      </div>
    `;
  }).join('');

  // Attach click listeners
  Array.from(els.grid.querySelectorAll('.algorithm-card')).forEach(card => {
    card.addEventListener('click', () => {
      const slug = card.getAttribute('data-slug');
      const algo = state.filtered.find(x => x.slug === slug);
      if (algo) openViewer(algo);
    });
  });
}

function openViewer(algo) {
  state.selected = algo;
  els.viewerTitle.textContent = algo.name;

  const langCount = Object.keys(algo.languages).length;
  els.viewerSubtitle.textContent = `Available in ${langCount} language${langCount !== 1 ? 's' : ''}`;

  els.viewer.classList.add('active');
  els.overlay.classList.add('active');
  document.body.style.overflow = 'hidden';

  buildTabs(algo);
}

function closeViewer() {
  state.selected = null;
  state.activeLang = null;
  els.viewer.classList.remove('active');
  els.overlay.classList.remove('active');
  document.body.style.overflow = '';
  els.tabs.innerHTML = '';
  els.codeText.className = '';
  els.codeText.textContent = '';
}

function buildTabs(algo) {
  const langExts = Object.keys(algo.languages);

  els.tabs.innerHTML = langExts.map((ext, idx) => {
    const label = SUPPORTED_EXT_MAP[ext]?.label || ext.toUpperCase();
    return `<button class="language-tab${idx === 0 ? ' active' : ''}" data-ext="${ext}">${label}</button>`;
  }).join('');

  Array.from(els.tabs.querySelectorAll('.language-tab')).forEach(btn => {
    btn.addEventListener('click', () => {
      setActiveTab(btn.getAttribute('data-ext'));
    });
  });

  if (langExts.length > 0) setActiveTab(langExts[0]);
}

function setActiveTab(ext) {
  state.activeLang = ext;

  Array.from(els.tabs.children).forEach(b =>
    b.classList.toggle('active', b.getAttribute('data-ext') === ext)
  );

  const files = state.selected.languages[ext] || [];
  const primary = choosePrimary(files);
  loadCode(primary, ext);
}

function choosePrimary(files) {
  if (files.length === 0) return null;

  const priorityPatterns = [/main\./i, /index\./i, /impl/i, /algorithm/i];
  const scored = files.map(f => {
    const name = f.split('/').pop();
    const score = priorityPatterns.reduce((s, re) => s + (re.test(name) ? 1 : 0), 0);
    return { f, score };
  }).sort((a, b) => b.score - a.score);

  return scored[0].f;
}

async function loadCode(filePath, ext) {
  if (!filePath) {
    els.codeText.textContent = 'No file available.';
    return;
  }

  try {
    const res = await fetch(filePath, { cache: 'no-store' });
    if (!res.ok) throw new Error('Failed to load file');

    const text = await res.text();
    const langId = SUPPORTED_EXT_MAP[ext]?.langId || '';

    els.codeText.className = langId ? `language-${langId}` : '';
    els.codeText.textContent = text;

    if (window.Prism) {
      Prism.highlightElement(els.codeText);
    }

    // Reset copy button state
    resetCopyButton();
  } catch (e) {
    console.error(e);
    els.codeText.textContent = 'Error loading file.';
  }
}

function copyCode() {
  const code = els.codeText.textContent;

  if (!code || code === 'No file available.' || code === 'Error loading file.') {
    return;
  }

  navigator.clipboard.writeText(code).then(() => {
    // Show success state
    els.copyBtn.classList.add('copied');
    els.copyBtn.querySelector('.copy-text').textContent = 'Copied!';

    // Reset after 2 seconds
    setTimeout(resetCopyButton, 2000);
  }).catch(err => {
    console.error('Failed to copy code:', err);
    // Fallback for older browsers
    try {
      const textArea = document.createElement('textarea');
      textArea.value = code;
      document.body.appendChild(textArea);
      textArea.select();
      document.execCommand('copy');
      document.body.removeChild(textArea);

      els.copyBtn.classList.add('copied');
      els.copyBtn.querySelector('.copy-text').textContent = 'Copied!';
      setTimeout(resetCopyButton, 2000);
    } catch (fallbackErr) {
      console.error('Fallback copy failed:', fallbackErr);
    }
  });
}

function resetCopyButton() {
  els.copyBtn.classList.remove('copied');
  els.copyBtn.querySelector('.copy-text').textContent = 'Copy';
}

function escapeHtml(str) {
  return (str || '').replace(/[&<>"']/g, c => ({
    '&': '&amp;',
    '<': '&lt;',
    '>': '&gt;',
    '"': '&quot;',
    "'": '&#39;'
  }[c]));
}

// Debounced search
let searchTimeout;
function handleSearch() {
  clearTimeout(searchTimeout);
  searchTimeout = setTimeout(() => {
    renderGrid();
  }, 150);
}

// Keyboard shortcuts
function handleKeydown(e) {
  if (e.key === 'Escape' && state.selected) {
    closeViewer();
  }
  if (e.key === '/' && !state.selected) {
    e.preventDefault();
    els.search.focus();
  }
}

// Event listeners
els.search.addEventListener('input', handleSearch);
els.closeViewer.addEventListener('click', closeViewer);
els.overlay.addEventListener('click', closeViewer);
els.copyBtn.addEventListener('click', copyCode);
document.addEventListener('keydown', handleKeydown);

// Initialize
loadManifest();
