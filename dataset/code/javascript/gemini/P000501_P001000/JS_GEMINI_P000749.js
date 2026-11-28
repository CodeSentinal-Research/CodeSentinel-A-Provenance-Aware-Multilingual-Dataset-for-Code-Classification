const fs = require('fs');
function varJumpPaths(n, m, r, c, path) {
    if (r === n && c === m) {
        console.log(path);
        return;
    }
    for (let k = 1; k <= m - c; k++) {
        varJumpPaths(n, m, r, c + k, path + `H${k}`);
    }
    for (let k = 1; k <= n - r; k++) {
        varJumpPaths(n, m, r + k, c, path + `V${k}`);
    }
    for (let k = 1; k <= Math.min(n - r, m - c); k++) {
        varJumpPaths(n, m, r + k, c + k, path + `D${k}`);
    }
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        varJumpPaths(parseInt(tokens[0], 10), parseInt(tokens[1], 10), 1, 1, "");
    }
}
main();