const fs = require('fs');

function wordBreakII(s, wordDict) {
    const memo = new Map();
    function dfs(rem) {
        if (memo.has(rem)) return memo.get(rem);
        if (rem.length === 0) return [''];
        const res = [];
        for (const word of wordDict) {
            if (rem.startsWith(word)) {
                const sub = dfs(rem.slice(word.length));
                for (const str of sub) {
                    res.push(word + (str.length === 0 ? '' : ' ' + str));
                }
            }
        }
        memo.set(rem, res);
        return res;
    }
    return dfs(s);
}

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const s = tokens[0];
        const dict = new Set(tokens.slice(1));
        const res = wordBreakII(s, dict);
        res.forEach(sent => console.log(sent));
    }
}

main();