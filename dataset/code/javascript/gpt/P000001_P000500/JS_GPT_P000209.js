// P000209 - Rotate Matrix Elements
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const r = tokens[p++], c = tokens[p++];
const a = Array.from({length: r}, () => tokens.slice(p, p += c));
const layers = Math.floor(Math.min(r, c) / 2);
for (let layer = 0; layer < layers; layer++) {
    const top = layer, left = layer;
    const bottom = r - 1 - layer, right = c - 1 - layer;
    let prev = a[top + 1][left];
    for (let i = left; i <= right; i++) { const temp = a[top][i]; a[top][i] = prev; prev = temp; }
    for (let i = top + 1; i <= bottom; i++) { const temp = a[i][right]; a[i][right] = prev; prev = temp; }
    for (let i = right - 1; i >= left; i--) { const temp = a[bottom][i]; a[bottom][i] = prev; prev = temp; }
    for (let i = bottom - 1; i >= top; i--) { const temp = a[i][left]; a[i][left] = prev; prev = temp; }
}
for (const row of a) console.log(row.join(" "));
