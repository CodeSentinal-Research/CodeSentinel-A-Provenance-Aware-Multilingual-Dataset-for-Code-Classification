const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const s = input[0];
        const n = parseInt(s, 10);
        const p = s.length;
        let sum = 0;
        for (let c of s) {
            sum += Math.pow(parseInt(c, 10), p);
        }
        console.log(sum === n ? "Armstrong" : "Not Armstrong");
    }
}
main();