const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        const g = lines[1].split(/\s+/).map(Number);
        const c = lines[2].split(/\s+/).map(Number);
        
        g.sort((a,b)=>a-b);
        c.sort((a,b)=>a-b);
        
        let i=0, j=0, count=0;
        while(i<n && j<m) {
            if(g[i] <= c[j]) { count++; i++; j++; }
            else j++;
        }
        console.log(count);
        rl.close();
    }
});
