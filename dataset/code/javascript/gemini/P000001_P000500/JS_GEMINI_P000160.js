const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 3) {
        const n = parseInt(input[0], 10), target = Number(input[1]);
        const set = new Set();
        for (let i = 0; i < n; i++) {
            const val = Number(input[2 + i]);
            const diff = target - val;
            if (set.has(diff)) {
                console.log(`${diff} ${val}`);
                return;
            }
            set.add(val);
        }
        console.log("No Pair");
    }
}
main();