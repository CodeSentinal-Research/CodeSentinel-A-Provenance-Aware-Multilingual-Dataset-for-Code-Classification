const fs = require('fs');
function fact(n) { let f = 1; for (let i = 2; i <= n; i++) f *= i; return f; }
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const s = input[0];
        const n = parseInt(s, 10);
        let sum = 0;
        for (let c of s) sum += fact(parseInt(c, 10));
        console.log(sum === n ? "Strong" : "Not Strong");
    }
}
main();