const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const q = parseInt(tokens[0], 10);
        let idx = 1;
        const counts = new Map();
        for (let i = 0; i < q; i++) {
            const cmd = tokens[idx];
            if (cmd === 'inc') {
                const k = tokens[idx+1];
                counts.set(k, (counts.get(k) || 0) + 1);
                idx += 2;
            } else if (cmd === 'dec') {
                const k = tokens[idx+1];
                const c = (counts.get(k) || 0) - 1;
                if (c <= 0) counts.delete(k);
                else counts.set(k, c);
                idx += 2;
            } else if (cmd === 'getMaxKey') {
                if (counts.size === 0) console.log("");
                else {
                    let maxV = -1, maxK = "";
                    for (const [k, v] of counts.entries()) {
                        if (v > maxV) { maxV = v; maxK = k; }
                    }
                    console.log(maxK);
                }
                idx += 1;
            } else if (cmd === 'getMinKey') {
                if (counts.size === 0) console.log("");
                else {
                    let minV = Infinity, minK = "";
                    for (const [k, v] of counts.entries()) {
                        if (v < minV) { minV = v; minK = k; }
                    }
                    console.log(minK);
                }
                idx += 1;
            }
        }
    }
}
main();