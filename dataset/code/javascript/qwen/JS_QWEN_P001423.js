const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let words = [];
        for (let i = 1; i <= n; i++) words.push(lines[i]);
        const pattern = lines[n+1];
        
        function match(word, pat) {
            if (word.length !== pat.length) return false;
            let w2p = {}, p2w = {};
            for (let i = 0; i < word.length; i++) {
                let w = word[i], p = pat[i];
                if (!w2p[w]) w2p[w] = p;
                if (!p2w[p]) p2w[p] = w;
                if (w2p[w] !== p || p2w[p] !== w) return false;
            }
            return true;
        }
        
        let res = words.filter(w => match(w, pattern));
        console.log(res.sort().join("\n"));
        rl.close();
    }
});
