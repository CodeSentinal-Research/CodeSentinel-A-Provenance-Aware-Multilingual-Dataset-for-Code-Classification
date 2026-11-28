const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const cap = parseInt(tokens[0], 10), q = parseInt(tokens[1], 10);
        let idx = 2;
        const keyMap = new Map();
        const freqMap = new Map();
        let minFreq = 0;
        for (let i = 0; i < q; i++) {
            const cmd = tokens[idx];
            if (cmd === 'put') {
                const k = parseInt(tokens[idx+1], 10), v = parseInt(tokens[idx+2], 10);
                if (cap > 0) {
                    if (keyMap.has(k)) {
                        const node = keyMap.get(k);
                        node.v = v;
                        const f = node.f;
                        freqMap.get(f).delete(k);
                        if (freqMap.get(f).size === 0 && f === minFreq) minFreq++;
                        node.f++;
                        if (!freqMap.has(node.f)) freqMap.set(node.f, new Set());
                        freqMap.get(node.f).add(k);
                    } else {
                        if (keyMap.size >= cap) {
                            const evictK = freqMap.get(minFreq).keys().next().value;
                            freqMap.get(minFreq).delete(evictK);
                            keyMap.delete(evictK);
                        }
                        const node = {k, v, f: 1};
                        keyMap.set(k, node);
                        if (!freqMap.has(1)) freqMap.set(1, new Set());
                        freqMap.get(1).add(k);
                        minFreq = 1;
                    }
                }
                idx += 3;
            } else if (cmd === 'get') {
                const k = parseInt(tokens[idx+1], 10);
                if (keyMap.has(k)) {
                    const node = keyMap.get(k);
                    const f = node.f;
                    freqMap.get(f).delete(k);
                    if (freqMap.get(f).size === 0 && f === minFreq) minFreq++;
                    node.f++;
                    if (!freqMap.has(node.f)) freqMap.set(node.f, new Set());
                    freqMap.get(node.f).add(k);
                    console.log(node.v);
                } else {
                    console.log(-1);
                }
                idx += 2;
            }
        }
    }
}
main();