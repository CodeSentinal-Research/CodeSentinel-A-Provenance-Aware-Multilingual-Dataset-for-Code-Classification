const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0];
        const t = lines[1];
        let memo = {};
        function numDistinct(i, j) {
            if(j===t.length) return 1;
            if(i===s.length) return 0;
            let key = `${i},${j}`;
            if(memo[key]!==undefined) return memo[key];
            let res = numDistinct(i+1, j);
            if(s[i]===t[j]) res += numDistinct(i+1, j+1);
            memo[key] = res;
            return res;
        }
        console.log(numDistinct(0, 0));
        rl.close();
    }
});
