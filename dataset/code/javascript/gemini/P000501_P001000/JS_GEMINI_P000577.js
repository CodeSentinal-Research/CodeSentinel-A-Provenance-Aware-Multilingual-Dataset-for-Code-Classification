const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim();
    if (!input) return;
    const tokens = input.split(/\s+/);
    if (tokens.length === 0 || ['null', '#', 'N'].includes(tokens[0])) return;
    const bottom = new Map();
    const q = [[0, 0]];
    while (q.length > 0) {
        const [idx, col] = q.shift();
        if (idx >= tokens.length || ['null', '#', 'N'].includes(tokens[idx])) continue;
        bottom.set(col, Number(tokens[idx]));
        const l = 2 * idx + 1, r = 2 * idx + 2;
        if (l < tokens.length) q.push([l, col - 1]);
        if (r < tokens.length) q.push([r, col + 1]);
    }
    const sortedCols = Array.from(bottom.keys()).sort((a, b) => a - b);
    console.log(sortedCols.map(c => bottom.get(c)).join(' '));
}
main();