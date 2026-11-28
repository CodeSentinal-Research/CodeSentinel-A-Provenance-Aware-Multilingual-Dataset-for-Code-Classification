const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 3 && tokens[0] !== '') {
        const beginWord = tokens[0], endWord = tokens[1];
        const n = parseInt(tokens[2], 10);
        let wordList = new Set(tokens.slice(3, 3 + n));
        if (!wordList.has(endWord)) return;
        let layer = new Map();
        layer.set(beginWord, [[beginWord]]);
        while (layer.size > 0) {
            if (layer.has(endWord)) {
                for (const path of layer.get(endWord)) {
                    console.log(path.join(' '));
                }
                return;
            }
            const newLayer = new Map();
            for (const [word, paths] of layer.entries()) {
                for (let i = 0; i < word.length; i++) {
                    for (let c = 97; c <= 122; c++) {
                        const nxt = word.slice(0, i) + String.fromCharCode(c) + word.slice(i + 1);
                        if (wordList.has(nxt)) {
                            if (!newLayer.has(nxt)) newLayer.set(nxt, []);
                            for (const p of paths) {
                                newLayer.get(nxt).push([...p, nxt]);
                            }
                        }
                    }
                }
            }
            for (const w of newLayer.keys()) wordList.delete(w);
            layer = newLayer;
        }
    }
}
main();