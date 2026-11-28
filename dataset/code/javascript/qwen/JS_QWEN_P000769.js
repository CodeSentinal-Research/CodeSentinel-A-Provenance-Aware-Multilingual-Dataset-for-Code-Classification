const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s1 = lines[0];
        const s2 = lines[1];
        let memo = {};
        function isScramble(s1, s2) {
            if (s1 === s2) return true;
            if (s1.length !== s2.length) return false;
            let key = s1 + "|" + s2;
            if (memo[key] !== undefined) return memo[key];
            let n = s1.length;
            for (let i = 1; i < n; i++) {
                if ((isScramble(s1.substring(0, i), s2.substring(0, i)) && isScramble(s1.substring(i), s2.substring(i))) ||
                    (isScramble(s1.substring(0, i), s2.substring(n - i)) && isScramble(s1.substring(i), s2.substring(0, n - i)))) {
                    memo[key] = true;
                    return true;
                }
            }
            memo[key] = false;
            return false;
        }
        console.log(isScramble(s1, s2) ? "true" : "false");
        rl.close();
    }
});
