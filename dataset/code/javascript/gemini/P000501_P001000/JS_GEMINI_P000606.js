const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const cap = parseInt(tokens[0], 10), q = parseInt(tokens[1], 10);
        let idx = 2;
        const cache = new Map();
        for (let i = 0; i < q; i++) {
            const cmd = tokens[idx];
            if (cmd === 'put') {
                const k = parseInt(tokens[idx+1], 10), v = parseInt(tokens[idx+2], 10);
                if (cache.has(k)) cache.delete(k);
                else if (cache.size >= cap) {
                    const firstKey = cache.keys().next().value;
                    cache.delete(firstKey);
                }
                cache.set(k, v);
                idx += 3;
            } else if (cmd === 'get') {
                const k = parseInt(tokens[idx+1], 10);
                if (cache.has(k)) {
                    const v = cache.get(k);
                    cache.delete(k);
                    cache.set(k, v);
                    console.log(v);
                } else {
                    console.log(-1);
                }
                idx += 2;
            }
        }
    }
}
main();