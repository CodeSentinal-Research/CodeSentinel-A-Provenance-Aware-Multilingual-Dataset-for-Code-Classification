const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const a = lines[0], b = lines[1];
        let n = a.length;
        for(let i=0; i<=n; i++) {
            let s = a.substring(0,i) + b.substring(n-i);
            if(s === s.split('').reverse().join('')) { console.log("Yes"); rl.close(); return; }
            s = b.substring(0,i) + a.substring(n-i);
            if(s === s.split('').reverse().join('')) { console.log("Yes"); rl.close(); return; }
        }
        console.log("No");
        rl.close();
    }
});
