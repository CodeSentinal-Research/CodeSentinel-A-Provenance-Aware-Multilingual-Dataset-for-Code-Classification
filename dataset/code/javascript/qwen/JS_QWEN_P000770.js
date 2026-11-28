const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const dims = lines[1].split(/\s+/).map(Number);
        let memo = {};
        function mcm(i, j) {
            if (i === j) return 0;
            let key = `${i},${j}`;
            if (memo[key] !== undefined) return memo[key];
            let minCost = Infinity;
            for (let k = i; k < j; k++) {
                let cost = mcm(i, k) + mcm(k + 1, j) + dims[i - 1] * dims[k] * dims[j];
                minCost = Math.min(minCost, cost);
            }
            memo[key] = minCost;
            return minCost;
        }
        console.log(mcm(1, n - 1));
        rl.close();
    }
});
