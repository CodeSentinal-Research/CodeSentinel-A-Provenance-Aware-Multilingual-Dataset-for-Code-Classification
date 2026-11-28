const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim();
    if (!input) return;
    const tokens = input.split(/\s+/);
    if (tokens.length === 0 || ['null', '#', 'N'].includes(tokens[0])) return;
    const top = new Map();
    const q = [[0, 0]];
    while (q.length > 0) {
        const [idx, col] = q.shift();
        if (idx >= tokens.length || ['null', '#', 'N'].includes(tokens[idx])) continue;
        if (!top.has(col)) top.set(col, Number(tokens[idx]));
        const l = 2 * idx + 1, r = 2 * idx + 2;
        if (l < tokens.length) q.push([l, col - 1]);
        if (r < tokens.length) q.push([r, col + 1]);
    }
    const sortedCols = Array.from(top.keys()).sort((a, b) => a - b);
    console.log(sortedCols.map(c => top.get(c)).join(' '));
}
main();