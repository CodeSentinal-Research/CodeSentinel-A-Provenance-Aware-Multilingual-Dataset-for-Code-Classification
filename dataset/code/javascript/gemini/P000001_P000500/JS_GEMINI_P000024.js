const fs = require('fs');

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const s = input[0];
        let sum = 0;
        for (let ch of s) {
            if (ch >= '0' && ch <= '9') {
                sum += parseInt(ch, 10);
            }
        }
        console.log(sum);
    }
}

main();