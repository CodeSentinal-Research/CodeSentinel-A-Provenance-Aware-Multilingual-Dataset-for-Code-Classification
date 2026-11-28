const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim();
    if (!input) return;
    const tokens = input.split(/\s+/);
    if (tokens.length === 0 || ['null', '#', 'N'].includes(tokens[0])) return;
    const cols = new Map();
    const q = [[0, 0]];
    while (q.length > 0) {
        const [idx, col] = q.shift();
        if (idx >= tokens.length || ['null', '#', 'N'].includes(tokens[idx])) continue;
        if (!cols.has(col)) cols.set(col, []);
        cols.get(col).push(Number(tokens[idx]));
        const l = 2 * idx + 1, r = 2 * idx + 2;
        if (l < tokens.length) q.push([l, col - 1]);
        if (r < tokens.length) q.push([r, col + 1]);
    }
    const sortedCols = Array.from(cols.keys()).sort((a, b) => a - b);
    for (const c of sortedCols) {
        console.log(cols.get(c).join(' '));
    }
}
main();