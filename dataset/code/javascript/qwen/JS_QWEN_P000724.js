const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const words = lines[1].split(/\s+/);
        let maxLen = 0;
        function dfs(idx, mask) {
            if (idx === n) {
                let str = "";
                for (let i = 0; i < 26; i++) {
                    if (mask & (1 << i)) str += String.fromCharCode(i + 97);
                }
                maxLen = Math.max(maxLen, str.length);
                return;
            }
            dfs(idx + 1, mask);
            let wordMask = 0, valid = true;
            for (let c of words[idx]) {
                let bit = 1 << (c.charCodeAt(0) - 97);
                if (wordMask & bit) { valid = false; break; }
                wordMask |= bit;
            }
            if (valid && !(mask & wordMask)) {
                dfs(idx + 1, mask | wordMask);
            }
        }
        dfs(0, 0);
        console.log(maxLen);
        rl.close();
    }
});
