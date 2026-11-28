const fs = require('fs');
function josephus(n, k) {
    if (n === 1) return 1;
    return (josephus(n - 1, k) + k - 1) % n + 1;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        console.log(josephus(parseInt(tokens[0], 10), parseInt(tokens[1], 10)));
    }
}
main();