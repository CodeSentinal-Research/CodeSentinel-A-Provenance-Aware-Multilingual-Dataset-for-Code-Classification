const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const target = Number(tokens[1]);
        const arr = tokens.slice(2, 2 + n).map(Number).sort((a, b) => a - b);
        let found = false;
        for (let i = 0; i < n - 2; i++) {
            let l = i + 1, r = n - 1;
            while (l < r) {
                const s = arr[i] + arr[l] + arr[r];
                if (s === target) { found = true; break; }
                else if (s < target) l++;
                else r--;
            }
            if (found) break;
        }
        console.log(found ? "Yes" : "No");
    }
}
main();