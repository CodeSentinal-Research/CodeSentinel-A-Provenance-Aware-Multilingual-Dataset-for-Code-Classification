const fs = require('fs');

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        const s = input[0].split('');
        const k = parseInt(input[1], 10);
        for (let start = 0; start < s.length; start += 2 * k) {
            let i = start, j = Math.min(start + k - 1, s.length - 1);
            while (i < j) {
                const tmp = s[i];
                s[i++] = s[j];
                s[j--] = tmp;
            }
        }
        console.log(s.join(''));
    }
}

main();