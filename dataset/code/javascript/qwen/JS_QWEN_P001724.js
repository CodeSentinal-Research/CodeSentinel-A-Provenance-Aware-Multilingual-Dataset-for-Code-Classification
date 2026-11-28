const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        const words = lines.slice(1, 1+n);
        
        let maxLen = 0;
        function dfs(idx, mask, len) {
            if (idx === n) {
                maxLen = Math.max(maxLen, len);
                return;
            }
            dfs(idx + 1, mask, len);
            let wordMask = 0;
            let valid = true;
            for (let c of words[idx]) {
                let bit = 1 << (c.charCodeAt(0) - 97);
                if (wordMask & bit) { valid = false; break; }
                wordMask |= bit;
            }
            if (valid && !(mask & wordMask)) {
                dfs(idx + 1, mask | wordMask, len + words[idx].length);
            }
        }
        dfs(0, 0, 0);
        console.log(maxLen);
        rl.close();
    }
});
