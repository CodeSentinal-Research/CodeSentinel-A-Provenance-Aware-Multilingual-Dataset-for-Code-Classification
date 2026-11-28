const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const s = input[0];
        const map = { I:1, V:5, X:10, L:50, C:100, D:500, M:1000 };
        let total = 0;
        for (let i = 0; i < s.length; i++) {
            const val = map[s[i]];
            if (i + 1 < s.length && val < map[s[i + 1]]) total -= val;
            else total += val;
        }
        console.log(total);
    }
}
main();