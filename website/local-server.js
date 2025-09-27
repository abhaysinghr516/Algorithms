/*
  local-server.js
  Minimal static server to serve the entire repo so the website can fetch code files via relative paths.
  Serves from repository root with caching disabled for dev.
*/

const http = require('http');
const fs = require('fs');
const path = require('path');

const REPO_ROOT = path.resolve(__dirname, '..');
const PORT = process.env.PORT || 8080;

const MIME = {
  '.html': 'text/html; charset=utf-8',
  '.css': 'text/css; charset=utf-8',
  '.js': 'application/javascript; charset=utf-8',
  '.json': 'application/json; charset=utf-8',
  '.md': 'text/markdown; charset=utf-8',
  '.txt': 'text/plain; charset=utf-8',
  '.png': 'image/png',
  '.jpg': 'image/jpeg',
  '.jpeg': 'image/jpeg',
  '.gif': 'image/gif',
  '.svg': 'image/svg+xml',
  '.ico': 'image/x-icon',
  '.c': 'text/plain; charset=utf-8',
  '.cpp': 'text/plain; charset=utf-8',
  '.go': 'text/plain; charset=utf-8',
  '.java': 'text/plain; charset=utf-8',
  '.py': 'text/plain; charset=utf-8',
  '.rs': 'text/plain; charset=utf-8'
};

function send(res, status, body, headers = {}) {
  res.writeHead(status, {
    'Cache-Control': 'no-store',
    'Access-Control-Allow-Origin': '*',
    ...headers
  });
  res.end(body);
}

const server = http.createServer((req, res) => {
  try {
    let urlPath = decodeURIComponent(req.url.split('?')[0]);
    if (urlPath === '/' || urlPath === '') {
      urlPath = '/website/index.html';
    }
    const absPath = path.join(REPO_ROOT, urlPath);

    // Prevent path traversal
    if (!absPath.startsWith(REPO_ROOT)) {
      return send(res, 403, 'Forbidden');
    }

    if (!fs.existsSync(absPath)) {
      return send(res, 404, 'Not Found');
    }

    const stat = fs.statSync(absPath);
    if (stat.isDirectory()) {
      const indexFile = path.join(absPath, 'index.html');
      if (fs.existsSync(indexFile)) {
        const data = fs.readFileSync(indexFile);
        return send(res, 200, data, { 'Content-Type': MIME['.html'] });
      }
      return send(res, 403, 'Forbidden');
    }

    const ext = path.extname(absPath).toLowerCase();
    const type = MIME[ext] || 'application/octet-stream';
    const data = fs.readFileSync(absPath);
    return send(res, 200, data, { 'Content-Type': type });
  } catch (err) {
    console.error(err);
    return send(res, 500, 'Internal Server Error');
  }
});

server.listen(PORT, () => {
  console.log(`Static server running at http://localhost:${PORT}`);
});
