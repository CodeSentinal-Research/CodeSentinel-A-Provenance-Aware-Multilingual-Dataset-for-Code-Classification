const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const sticks = lines[1].split(/\s+/).map(Number);
        let sum = sticks.reduce((a,b)=>a+b, 0);
        if (sum % 4 !== 0) { console.log("false"); rl.close(); return; }
        let side = sum / 4;
        sticks.sort((a,b)=>b-a);
        let sides = [0,0,0,0];
        function dfs(idx) {
            if (idx === n) return sides.every(s => s === side);
            for (let i = 0; i < 4; i++) {
                if (sides[i] + sticks[idx] <= side) {
                    sides[i] += sticks[idx];
                    if (dfs(idx + 1)) return true;
                    sides[i] -= sticks[idx];
                }
                if (sides[i] === 0) break;
            }
            return false;
        }
        console.log(dfs(0) ? "true" : "false");
        rl.close();
    }
});
