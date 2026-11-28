const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        let nums = tokens.slice(1, 1 + n).map(Number);
        let passes = 0;
        while (nums.length > 0) {
            passes++;
            const rem = [];
            let last = -Infinity;
            for (const x of nums) {
                if (x > last) {
                    last = x;
                } else {
                    rem.push(x);
                }
            }
            nums = rem;
        }
        console.log(passes);
    }
}
main();