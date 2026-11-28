const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const weeks = lines[1].split(/\s+/).map(Number);
        
        let maxWeeks = Math.max(...weeks);
        let sumWeeks = weeks.reduce((a,b)=>a+b, 0);
        
        if(maxWeeks > sumWeeks-maxWeeks+1) console.log(2*(sumWeeks-maxWeeks)+1);
        else console.log(sumWeeks);
        rl.close();
    }
});
