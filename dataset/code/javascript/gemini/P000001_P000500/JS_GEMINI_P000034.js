const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const n = parseInt(input[0], 10);
        if (n <= 1) { console.log("Not Perfect"); return; }
        let sum = 0;
        for (let i = 1; i < n; i++) if (n % i === 0) sum += i;
        console.log(sum === n ? "Perfect" : "Not Perfect");
    }
}
main();