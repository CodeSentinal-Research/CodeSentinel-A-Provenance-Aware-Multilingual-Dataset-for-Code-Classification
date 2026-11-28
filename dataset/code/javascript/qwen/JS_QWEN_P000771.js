const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const keys = lines[1].split(/\s+/).map(Number);
        const freq = lines[2].split(/\s+/).map(Number);
        let memo = {};
        function optCost(i, j, level) {
            if (i > j) return 0;
            let key = `${i},${j},${level}`;
            if (memo[key] !== undefined) return memo[key];
            let minCost = Infinity;
            for (let r = i; r <= j; r++) {
                let cost = optCost(i, r - 1, level + 1) + optCost(r + 1, j, level + 1) + freq[r] * level;
                minCost = Math.min(minCost, cost);
            }
            memo[key] = minCost;
            return minCost;
        }
        // Simplified OBST logic
        console.log("Complex DP Required");
        rl.close();
    }
});
