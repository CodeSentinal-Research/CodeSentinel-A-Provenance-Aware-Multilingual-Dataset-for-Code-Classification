const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [n, addRocks] = lines[0].split(/\s+/).map(Number);
        const cap = lines[1].split(/\s+/).map(Number);
        const cur = lines[2].split(/\s+/).map(Number);
        
        let rem = [];
        for(let i=0; i<n; i++) rem.push(cap[i]-cur[i]);
        rem.sort((a,b)=>a-b);
        
        let count=0;
        for(let r of rem) {
            if(addRocks>=r) { addRocks-=r; count++; }
            else break;
        }
        console.log(count);
        rl.close();
    }
});
