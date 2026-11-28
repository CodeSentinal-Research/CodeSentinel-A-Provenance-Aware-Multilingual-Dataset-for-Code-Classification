const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        nums.sort((a,b)=>b-a);
        let prefix=0, count=0;
        for(let x of nums) {
            prefix+=x;
            if(prefix>0) count++;
        }
        console.log(count);
        rl.close();
    }
});
