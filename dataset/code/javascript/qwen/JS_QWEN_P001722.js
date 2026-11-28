const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const sticks = lines[0].split(/\s+/).map(Number);
        let sum = sticks.reduce((a,b)=>a+b, 0);
        if (sum % 4 !== 0) { console.log("false"); rl.close(); return; }
        let side = sum / 4;
        sticks.sort((a,b)=>b-a);
        let buckets = [0,0,0,0];
        function dfs(idx) {
            if (idx === sticks.length) return true;
            for (let i = 0; i < 4; i++) {
                if (buckets[i] + sticks[idx] <= side) {
                    buckets[i] += sticks[idx];
                    if (dfs(idx + 1)) return true;
                    buckets[i] -= sticks[idx];
                }
                if (buckets[i] === 0) break;
            }
            return false;
        }
        console.log(dfs(0) ? "true" : "false");
        rl.close();
    }
});
