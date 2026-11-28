const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0].split(' ')[1])+2) {
        const [n, qStr] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        const q = parseInt(qStr);
        let res = [];
        for(let i=2; i<2+q; i++) {
            let x = parseInt(lines[i]);
            res.push(arr.includes(x) ? "Found" : "Not Found");
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
