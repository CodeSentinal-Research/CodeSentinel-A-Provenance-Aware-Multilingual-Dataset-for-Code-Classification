const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const s = input[0];
        let count = 0;
        for (let c of s) {
            if (c >= '0' && c <= '9' && parseInt(c, 10) % 2 === 0) count++;
        }
        console.log(count);
    }
}
main();