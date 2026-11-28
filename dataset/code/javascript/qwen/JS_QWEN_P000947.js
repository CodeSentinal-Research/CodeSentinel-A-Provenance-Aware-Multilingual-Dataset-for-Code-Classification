const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [maxChoosable, desiredTotal] = line.split(/\s+/).map(Number);
        if(desiredTotal <= 0) { console.log("true"); rl.close(); return; }
        if(maxChoosable * (maxChoosable + 1) / 2 < desiredTotal) { console.log("false"); rl.close(); return; }
        
        let memo = {};
        function canWin(used, remaining) {
            if(remaining <= 0) return false;
            if(memo[used] !== undefined) return memo[used];
            
            for(let i=1; i<=maxChoosable; i++) {
                let mask = 1 << i;
                if(!(used & mask)) {
                    if(!canWin(used | mask, remaining - i)) {
                        memo[used] = true;
                        return true;
                    }
                }
            }
            memo[used] = false;
            return false;
        }
        console.log(canWin(0, desiredTotal) ? "true" : "false");
        rl.close();
    }
});
