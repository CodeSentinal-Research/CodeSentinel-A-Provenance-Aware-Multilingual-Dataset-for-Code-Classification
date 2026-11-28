const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let count = {};
    for (let i = 1; i <= n; i++) {
        let s = i.toString().split('').reduce((a,b)=>a+parseInt(b), 0);
        count[s] = (count[s] || 0) + 1;
    }
    let maxVal = Math.max(...Object.values(count));
    let groups = Object.values(count).filter(v => v === maxVal).length;
    console.log(groups);
    rl.close();
});
