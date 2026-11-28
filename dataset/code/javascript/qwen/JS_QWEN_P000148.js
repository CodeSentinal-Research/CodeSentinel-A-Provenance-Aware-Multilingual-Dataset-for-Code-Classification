const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        let mat = [];
        for(let i=1; i<=n; i++) mat.push(lines[i].split(/\s+/).map(Number));
        let sym = true;
        for(let i=0; i<n; i++) {
            for(let j=0; j<n; j++) {
                if(mat[i][j] !== mat[j][i]) sym = false;
            }
        }
        console.log(sym ? "Symmetric" : "Not Symmetric");
        rl.close();
    }
});
