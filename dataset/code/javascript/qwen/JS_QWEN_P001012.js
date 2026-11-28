const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        const h1 = lines[1].split(/\s+/).map(Number);
        const h2 = lines[2].split(/\s+/).map(Number);
        const merged = [...h1, ...h2];
        // Build Min Heap
        for (let i = Math.floor(merged.length / 2) - 1; i >= 0; i--) {
            let idx = i;
            while (true) {
                let l = 2 * idx + 1, r = 2 * idx + 2, minIdx = idx;
                if (l < merged.length && merged[l] < merged[minIdx]) minIdx = l;
                if (r < merged.length && merged[r] < merged[minIdx]) minIdx = r;
                if (minIdx !== idx) {
                    [merged[idx], merged[minIdx]] = [merged[minIdx], merged[idx]];
                    idx = minIdx;
                } else break;
            }
        }
        console.log(merged.join(" "));
        rl.close();
    }
});
