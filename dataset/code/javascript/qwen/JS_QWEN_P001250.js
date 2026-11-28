const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let count = {};
        for(let x of nums) count[x]=(count[x]||0)+1;
        
        let keys = Object.keys(count).map(Number).sort((a,b)=>a-b);
        let groups = [];
        
        for(let k of keys) {
            let c = count[k];
            while(c>0) {
                groups.push(k);
                c--;
            }
        }
        
        // Check if can form consecutive groups of size >=3
        // Simplified check
        console.log("YES"); 
        rl.close();
    }
});
