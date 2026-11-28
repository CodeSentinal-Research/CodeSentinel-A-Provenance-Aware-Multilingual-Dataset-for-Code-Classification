const fs = require('fs');
function dfs(cur, n) {
    if (cur > n) return;
    console.log(cur);
    for (let i = 0; i < 10; i++) {
        if (cur * 10 + i <= n) dfs(cur * 10 + i, n);
        else break;
    }
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        for (let i = 1; i <= 9 && i <= n; i++) dfs(i, n);
    }
}
main();