const fs = require('fs');
function diagonalPaths(n, m, r, c, path) {
    if (r === n && c === m) {
        console.log(path);
        return;
    }
    if (r < n && c < m) diagonalPaths(n, m, r + 1, c + 1, path + "D");
    if (c < m) diagonalPaths(n, m, r, c + 1, path + "H");
    if (r < n) diagonalPaths(n, m, r + 1, c, path + "V");
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        diagonalPaths(parseInt(tokens[0], 10), parseInt(tokens[1], 10), 1, 1, "");
    }
}
main();