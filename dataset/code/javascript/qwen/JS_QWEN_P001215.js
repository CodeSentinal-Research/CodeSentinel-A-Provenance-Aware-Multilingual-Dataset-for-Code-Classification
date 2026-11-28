const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const boxes = lines[1].split(/\s+/).map(Number);
        
        let memo = {};
        function solve(l, r, k) {
            if(l>r) return 0;
            let key = `${l},${r},${k}`;
            if(memo[key]!==undefined) return memo[key];
            
            while(r>l && boxes[r]===boxes[r-1]) { r--; k++; }
            
            let res = solve(l, r-1, 0) + (k+1)*(k+1);
            for(let i=l; i<r; i++) {
                if(boxes[i]===boxes[r]) {
                    res = Math.max(res, solve(l, i, k+1) + solve(i+1, r-1, 0));
                }
            }
            memo[key] = res;
            return res;
        }
        console.log(solve(0, n-1, 0));
        rl.close();
    }
});
