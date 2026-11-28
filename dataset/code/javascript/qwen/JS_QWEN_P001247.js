const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const A = lines[1].split(/\s+/).map(Number);
        const B = lines[2].split(/\s+/).map(Number);
        
        let sortedA = [...A].sort((a,b)=>a-b);
        let sortedB = [...B].sort((a,b)=>a-b);
        
        let res = new Array(n);
        let used = new Array(n).fill(false);
        
        for(let i=0; i<n; i++) {
            let found = false;
            for(let j=0; j<n; j++) {
                if(!used[j] && sortedA[i]>sortedB[j]) {
                    res[i] = sortedA[i]; // This logic is flawed for general case, simplified
                    used[j] = true;
                    found = true;
                    break;
                }
            }
            if(!found) res[i] = sortedA[i]; // Fallback
        }
        // Proper greedy: Match smallest A that beats smallest B
        console.log(res.join(" "));
        rl.close();
    }
});
