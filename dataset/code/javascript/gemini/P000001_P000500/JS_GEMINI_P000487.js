const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const h = tokens.slice(1, 1 + n).map(Number);
        let l = 0, r = n - 1;
        let lMax = 0, rMax = 0;
        let water = 0;
        while (l < r) {
            if (h[l] < h[r]) {
                if (h[l] >= lMax) lMax = h[l];
                else water += lMax - h[l];
                l++;
            } else {
                if (h[r] >= rMax) rMax = h[r];
                else water += rMax - h[r];
                r--;
            }
        }
        console.log(water);
    }
}
main();