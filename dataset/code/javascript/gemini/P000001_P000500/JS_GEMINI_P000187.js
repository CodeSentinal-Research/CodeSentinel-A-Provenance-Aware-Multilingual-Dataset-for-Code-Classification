const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        const n = parseInt(input[0], 10);
        const set = new Set(input.slice(1, n + 1).map(Number));
        let val = 1;
        // Shrink window from the left while duplicate element exists
        while (set.has(val)) val++;
        console.log(val);
    }
}
main();