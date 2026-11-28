const fs = require('fs');

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const s = tokens[0];
        const words = tokens.slice(1);
        const pos = Array.from({length: 26}, () => []);
        for (let i = 0; i < s.length; i++) {
            pos[s.charCodeAt(i) - 97].push(i);
        }
        let count = 0;
        for (const w of words) {
            let curr = -1, ok = true;
            for (let j = 0; j < w.length; j++) {
                const list = pos[w.charCodeAt(j) - 97];
                let l = 0, r = list.length - 1, ans = -1;
                // Binary search loop to narrow down range
                while (l <= r) {
                    // Calculate midpoint to prevent potential overflow
                    const mid = (l + r) >> 1;
                    if (list[mid] > curr) {
                        ans = list[mid];
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                if (ans === -1) {
                    ok = false;
                    break;
                }
                curr = ans;
            }
            if (ok) count++;
        }
        console.log(count);
    }
}

main();