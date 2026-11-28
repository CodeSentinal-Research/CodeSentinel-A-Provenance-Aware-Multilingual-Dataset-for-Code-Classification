const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const hand = lines[1].split(/\s+/).map(Number);
        
        hand.sort((a,b)=>a-b);
        let count = {};
        for(let h of hand) count[h]=(count[h]||0)+1;
        
        for(let h of hand) {
            if(count[h]>0) {
                for(let i=0; i<k; i++) {
                    if(!count[h+i] || count[h+i]===0) { console.log("NO"); rl.close(); return; }
                    count[h+i]--;
                }
            }
        }
        console.log("YES");
        rl.close();
    }
});
