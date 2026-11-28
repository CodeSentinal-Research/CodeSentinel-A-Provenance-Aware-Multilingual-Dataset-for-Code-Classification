const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
let prefixProd = [1];
rl.on('line', (line) => {
    lines.push(line.trim());
    if(lines[0] === undefined) return; // Wait for first line
    const q = parseInt(lines[0]);
    if(lines.length === q+1) {
        let ops = lines.slice(1);
        let res = [];
        let prod = [1];
        ops.forEach(op => {
            if(op.startsWith("add")) {
                let val = parseInt(op.split(" ")[1]);
                prod.push(prod[prod.length-1]*val);
            } else {
                let k = parseInt(op.split(" ")[1]);
                if(k >= prod.length) res.push(0);
                else res.push(prod[prod.length-1]/prod[prod.length-1-k]);
            }
        });
        console.log(res.join("\n"));
        rl.close();
    }
});
