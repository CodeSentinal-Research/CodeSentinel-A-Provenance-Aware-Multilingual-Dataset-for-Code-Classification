const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const s = input[0];
        const n = parseInt(s, 10);
        let dSum = 0;
        for (let c of s) if (c >= '0' && c <= '9') dSum += parseInt(c, 10);
        console.log(dSum > 0 && n % dSum === 0 ? "Harshad" : "Not Harshad");
    }
}
main();