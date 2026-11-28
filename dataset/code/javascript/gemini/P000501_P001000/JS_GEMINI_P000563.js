const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 3 && tokens[0] !== '') {
        const beginWord = tokens[0], endWord = tokens[1];
        const n = parseInt(tokens[2], 10);
        const wordList = new Set(tokens.slice(3, 3 + n));
        if (!wordList.has(endWord)) { console.log(0); return; }
        const q = [[beginWord, 1]];
        const vis = new Set([beginWord]);
        let ans = 0;
        while (q.length > 0) {
            const [word, len] = q.shift();
            if (word === endWord) { ans = len; break; }
            for (let i = 0; i < word.length; i++) {
                for (let c = 97; c <= 122; c++) {
                    const nxt = word.slice(0, i) + String.fromCharCode(c) + word.slice(i + 1);
                    if (wordList.has(nxt) && !vis.has(nxt)) {
                        vis.add(nxt);
                        q.push([nxt, len + 1]);
                    }
                }
            }
        }
        console.log(ans);
    }
}
main();