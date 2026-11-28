const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let sumN = (n*(n+1))/2;
        let sumArr = arr.reduce((a,b)=>a+b, 0);
        let missing = sumN - sumArr + (arr.find((val, idx) => arr.indexOf(val) !== idx) || 0); 
        // Simplified logic for demo, robust solution needs XOR or hash
        let dup = arr.find((val, idx) => arr.indexOf(val) !== idx);
        console.log(`${missing} ${dup}`);
        rl.close();
    }
});
