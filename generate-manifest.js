/*
  generate-manifest.js
  Scans the repository for algorithm implementations and generates website/algorithms.json
  Supported extensions: .js, .c, .cpp, .go, .java, .py, .rs
*/

const fs = require('fs');
const path = require('path');

const REPO_ROOT = __dirname;
const WEBSITE_DIR = path.join(REPO_ROOT, 'website');
const OUTPUT_FILE = path.join(WEBSITE_DIR, 'algorithms.json');

const SUPPORTED = new Set(['.js', '.c', '.cpp', '.go', '.java', '.py', '.rs']);
const IGNORE_DIRS = new Set(['.git', '.github', '.vscode', 'website', 'node_modules', '.kiro']);
const IGNORE_FILES = new Set(['.gitignore', '.gitkeep', 'README.md', 'readme.md', '.DS_Store']);

function listTopLevelAlgorithmDirs(root) {
  try {
    return fs.readdirSync(root, { withFileTypes: true })
      .filter(d => {
        if (!d.isDirectory()) return false;
        if (IGNORE_DIRS.has(d.name)) return false;
        if (d.name.startsWith('.')) return false;

        // Additional check: directory should contain algorithm files
        const dirPath = path.join(root, d.name);
        return hasAlgorithmFiles(dirPath);
      })
      .map(d => path.join(root, d.name));
  } catch (error) {
    console.error(`Error reading directory ${root}:`, error.message);
    return [];
  }
}

function hasAlgorithmFiles(dir) {
  try {
    const files = walkFiles(dir);
    return files.some(f => SUPPORTED.has(path.extname(f).toLowerCase()));
  } catch {
    return false;
  }
}

function walkFiles(dir) {
  const out = [];
  const stack = [dir];

  while (stack.length) {
    const current = stack.pop();

    try {
      const entries = fs.readdirSync(current, { withFileTypes: true });

      for (const e of entries) {
        const full = path.join(current, e.name);

        if (e.isDirectory()) {
          // Skip ignored directories and hidden directories
          if (!IGNORE_DIRS.has(e.name) && !e.name.startsWith('.')) {
            stack.push(full);
          }
        } else if (e.isFile()) {
          // Skip ignored files and only include supported extensions
          if (!IGNORE_FILES.has(e.name) && SUPPORTED.has(path.extname(e.name).toLowerCase())) {
            out.push(full);
          }
        }
      }
    } catch (error) {
      console.warn(`Warning: Could not read directory ${current}:`, error.message);
    }
  }

  return out;
}

function firstReadableLine(p) {
  try {
    const content = fs.readFileSync(p, 'utf8');
    const lines = content.split(/\r?\n/);

    for (const line of lines) {
      const trimmed = line.trim();
      if (trimmed.length > 0) {
        // Remove markdown headings and return clean description
        return trimmed.replace(/^#+\s*/, '').replace(/^\*+\s*/, '').trim();
      }
    }

    return '';
  } catch {
    return '';
  }
}

function generateDescription(algoName) {
  // Generate a basic description if no README is found
  const cleanName = algoName.replace(/Algorithm$/, '').trim();
  return `${cleanName} Algorithm`;
}

function toSlug(name) {
  return name.toLowerCase().replace(/[^a-z0-9]+/g, '-').replace(/^-+|-+$/g, '');
}

function buildManifest() {
  const manifest = [];
  const algDirs = listTopLevelAlgorithmDirs(REPO_ROOT);

  console.log(`Found ${algDirs.length} algorithm directories:`);

  for (const dir of algDirs) {
    const algoName = path.basename(dir);
    console.log(`Processing: ${algoName}`);

    const files = walkFiles(dir);
    const byExt = {};
    let fileCount = 0;

    for (const f of files) {
      const ext = path.extname(f).toLowerCase();
      if (!SUPPORTED.has(ext)) continue;

      // Convert path separators to forward slashes for web compatibility
      const relFromRoot = path.relative(REPO_ROOT, f).split(path.sep).join('/');
      const relFromWebsite = '../' + relFromRoot;

      byExt[ext] = byExt[ext] || [];
      byExt[ext].push(relFromWebsite);
      fileCount++;
    }

    // Only include if there is at least one supported file
    const langKeys = Object.keys(byExt);
    if (langKeys.length === 0) {
      console.warn(`  Warning: No supported files found in ${algoName}`);
      continue;
    }

    // Sort file lists for consistency
    for (const k of langKeys) {
      byExt[k].sort();
    }

    // Try to read description from README files
    const readmePaths = [
      path.join(dir, 'README.md'),
      path.join(dir, 'readme.md'),
      path.join(dir, 'README.txt'),
      path.join(dir, 'readme.txt')
    ];

    let description = '';
    for (const readmePath of readmePaths) {
      if (fs.existsSync(readmePath)) {
        description = firstReadableLine(readmePath);
        if (description) break;
      }
    }

    // Fallback to generated description
    if (!description) {
      description = generateDescription(algoName);
    }

    console.log(`  Added: ${langKeys.length} languages, ${fileCount} files`);

    manifest.push({
      name: algoName,
      slug: toSlug(algoName),
      description,
      languages: byExt
    });
  }

  // Sort algorithms alphabetically
  manifest.sort((a, b) => a.name.localeCompare(b.name));

  console.log(`\nGenerated manifest with ${manifest.length} algorithms`);
  return manifest;
}

function ensureDir(p) {
  if (!fs.existsSync(p)) fs.mkdirSync(p, { recursive: true });
}

function main() {
  console.log('🔍 Scanning for algorithm implementations...\n');
  console.log(`Repository root: ${REPO_ROOT}`);
  console.log(`Output file: ${OUTPUT_FILE}\n`);

  ensureDir(WEBSITE_DIR);

  const manifest = buildManifest();

  if (manifest.length === 0) {
    console.error('❌ No algorithms found! Check your directory structure.');
    process.exit(1);
  }

  try {
    fs.writeFileSync(OUTPUT_FILE, JSON.stringify(manifest, null, 2), 'utf8');
    console.log(`\n✅ Successfully generated ${path.relative(REPO_ROOT, OUTPUT_FILE)}`);
    console.log(`📊 Total algorithms: ${manifest.length}`);

    // Show summary of languages
    const allLanguages = new Set();
    manifest.forEach(algo => {
      Object.keys(algo.languages).forEach(ext => allLanguages.add(ext));
    });
    console.log(`🔤 Languages found: ${Array.from(allLanguages).sort().join(', ')}`);

  } catch (error) {
    console.error('❌ Error writing manifest file:', error.message);
    process.exit(1);
  }
}

if (require.main === module) {
  main();
}
