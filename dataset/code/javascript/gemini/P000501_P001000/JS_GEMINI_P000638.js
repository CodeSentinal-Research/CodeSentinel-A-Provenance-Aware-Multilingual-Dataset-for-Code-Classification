const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const q = parseInt(tokens[0], 10);
        let idx = 1;
        const poly = new Map();
        for (let j = 0; j < q; j++) {
            const cmd = tokens[idx];
            if (cmd === 'insert') {
                const c = parseInt(tokens[idx+1], 10), e = parseInt(tokens[idx+2], 10);
                poly.set(e, (poly.get(e) || 0) + c);
                if (poly.get(e) === 0) poly.delete(e);
                idx += 3;
            } else if (cmd === 'delete') {
                const e = parseInt(tokens[idx+1], 10);
                poly.delete(e);
                idx += 2;
            } else if (cmd === 'evaluate') {
                const x = parseInt(tokens[idx+1], 10);
                let ans = 0;
                for (const [e, c] of poly.entries()) {
                    ans += c * Math.pow(x, e);
                }
                console.log(ans);
                idx += 2;
            } else if (cmd === 'display') {
                const sorted = Array.from(poly.entries()).sort((a, b) => b[0] - a[0]);
                if (sorted.length === 0) {
                    console.log("0");
                } else {
                    const terms = sorted.map(([e, c]) => e > 0 ? `${c}x^${e}` : `${c}`);
                    console.log(terms.join(' + '));
                }
                idx += 1;
            }
        }
    }
}
main();