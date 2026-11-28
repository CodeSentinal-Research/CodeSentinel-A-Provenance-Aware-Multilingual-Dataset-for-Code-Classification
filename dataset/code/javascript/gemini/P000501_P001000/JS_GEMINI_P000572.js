const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim();
    if (!input) return;
    const tokens = input.split(/\s+/);
    if (tokens.length === 0 || ['null', '#', 'N'].includes(tokens[0])) return;
    const levels = [];
    const q = [[0, 0]];
    while (q.length > 0) {
        const [idx, lvl] = q.shift();
        if (idx >= tokens.length || ['null', '#', 'N'].includes(tokens[idx])) continue;
        if (!levels[lvl]) levels[lvl] = [];
        levels[lvl].push(Number(tokens[idx]));
        const l = 2 * idx + 1, r = 2 * idx + 2;
        if (l < tokens.length) q.push([l, lvl + 1]);
        if (r < tokens.length) q.push([r, lvl + 1]);
    }
    for (const lvl of levels) {
        if (lvl) console.log(lvl.join(' '));
    }
}
main();