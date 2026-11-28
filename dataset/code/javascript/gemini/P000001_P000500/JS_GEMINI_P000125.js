const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 3) {
        const n = parseInt(input[0], 10), target = Number(input[1]);
        const map = new Map();
        for (let i = 0; i < n; i++) {
            const val = Number(input[2 + i]);
            const diff = target - val;
            if (map.has(diff)) {
                console.log(`${map.get(diff)} ${i}`);
                return;
            }
            map.set(val, i);
        }
    }
}
main();