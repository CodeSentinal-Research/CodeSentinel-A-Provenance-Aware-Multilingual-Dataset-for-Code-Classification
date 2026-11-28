const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const top = lines[1].split(/\s+/).map(Number);
        const bottom = lines[2].split(/\s+/).map(Number);
        
        let swapsTop=0, swapsBot=0;
        let target=top[0];
        let possible=true;
        
        for(let i=0; i<n; i++) {
            if(top[i]!==target && bottom[i]!==target) { possible=false; break; }
            if(top[i]!==target) swapsTop++;
            if(bottom[i]!==target) swapsBot++;
        }
        
        if(!possible) {
            target=bottom[0];
            possible=true; swapsTop=0; swapsBot=0;
            for(let i=0; i<n; i++) {
                if(top[i]!==target && bottom[i]!==target) { possible=false; break; }
                if(top[i]!==target) swapsTop++;
                if(bottom[i]!==target) swapsBot++;
            }
        }
        
        if(!possible) console.log(-1);
        else console.log(Math.min(swapsTop, swapsBot));
        rl.close();
    }
});
