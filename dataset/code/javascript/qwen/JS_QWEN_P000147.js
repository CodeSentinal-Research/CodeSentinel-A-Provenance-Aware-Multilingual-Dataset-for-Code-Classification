const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        let mat = [];
        for(let i=1; i<=n; i++) mat.push(lines[i].split(/\s+/).map(Number));
        let main = [], anti = [];
        for(let i=0; i<n; i++) {
            main.push(mat[i][i]);
            anti.push(mat[i][n-1-i]);
        }
        console.log(main.join(" "));
        console.log(anti.join(" "));
        rl.close();
    }
});
