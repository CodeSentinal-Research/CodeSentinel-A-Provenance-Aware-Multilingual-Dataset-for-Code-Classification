const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0];
        const p = lines[1];
        let memo = {};
        function isMatch(i, j) {
            if(j===p.length) return i===s.length;
            let key = `${i},${j}`;
            if(memo[key]!==undefined) return memo[key];
            let firstMatch = i<s.length && (p[j]==='?' || p[j]===s[i]);
            if(p[j]==='*') {
                memo[key] = isMatch(i, j+1) || (firstMatch && isMatch(i+1, j));
            } else {
                memo[key] = firstMatch && isMatch(i+1, j+1);
            }
            return memo[key];
        }
        console.log(isMatch(0, 0) ? "true" : "false");
        rl.close();
    }
});
