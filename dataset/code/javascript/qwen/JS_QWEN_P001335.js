const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let words = [];
        for(let i=1; i<=n; i++) words.push(lines[i]);
        
        let maxLen = 0;
        function dfs(idx, mask, len) {
            if(idx===n) { maxLen=Math.max(maxLen, len); return; }
            // Check if word[idx] has unique chars relative to current mask
            let wordMask = 0;
            let valid = true;
            for(let c of words[idx]) {
                let bit = 1 << (c.charCodeAt(0)-97);
                if(wordMask & bit) { valid=false; break; }
                wordMask |= bit;
            }
            if(valid && !(mask & wordMask)) {
                dfs(idx+1, mask|wordMask, len+words[idx].length);
            }
            dfs(idx+1, mask, len);
        }
        dfs(0, 0, 0);
        console.log(maxLen);
        rl.close();
    }
});
