const fs = require('fs');
function climbStairs(n) {
    if (n <= 1) return 1n;
    let a = 1n, b = 1n;
    for (let i = 2; i <= n; i++) {
        let c = a + b; a = b; b = c;
    }
    return b;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        console.log(climbStairs(parseInt(tokens[0], 10)).toString());
    }
}
main();