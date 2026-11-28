const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        let mat = [];
        for(let i=1; i<=n; i++) mat.push(lines[i].split(/\s+/).map(Number));
        let prod = Array(n).fill(0).map(()=>Array(n).fill(0));
        for(let i=0; i<n; i++) {
            for(let j=0; j<n; j++) {
                for(let k=0; k<n; k++) prod[i][j] += mat[i][k]*mat[j][k]; // Transpose mult
            }
        }
        let ortho = true;
        for(let i=0; i<n; i++) for(let j=0; j<n; j++) {
            if(i===j && prod[i][j]!==1) ortho=false;
            if(i!==j && prod[i][j]!==0) ortho=false;
        }
        console.log(ortho ? "Yes" : "No");
        rl.close();
    }
});
