const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [rows, cols, rC, cC] = line.split(/\s+/).map(Number);
        let cells = [];
        for(let i=0; i<rows; i++) {
            for(let j=0; j<cols; j++) {
                cells.push([i,j, Math.abs(i-rC)+Math.abs(j-cC)]);
            }
        }
        cells.sort((a,b)=>a[2]-b[2]);
        console.log(cells.map(c=>`[${c[0]},${c[1]}]`).join(" "));
        rl.close();
    }
});
