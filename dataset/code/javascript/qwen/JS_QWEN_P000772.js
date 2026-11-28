const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [e, f] = line.split(/\s+/).map(Number);
        let memo = {};
        function eggDrop(e, f) {
            if (f === 0 || f === 1) return f;
            if (e === 1) return f;
            let key = `${e},${f}`;
            if (memo[key] !== undefined) return memo[key];
            let minAttempts = Infinity;
            for (let k = 1; k <= f; k++) {
                let res = 1 + Math.max(eggDrop(e - 1, k - 1), eggDrop(e, f - k));
                minAttempts = Math.min(minAttempts, res);
            }
            memo[key] = minAttempts;
            return minAttempts;
        }
        console.log(eggDrop(e, f));
        rl.close();
    }
});
