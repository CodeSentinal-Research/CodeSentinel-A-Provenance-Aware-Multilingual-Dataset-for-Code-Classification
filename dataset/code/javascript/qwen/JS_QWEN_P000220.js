const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        let mat = [];
        for(let i=1; i<=n; i++) mat.push(lines[i].split(/\s+/).map(Number));
        let candidate = 0;
        for(let i=1; i<n; i++) if(mat[candidate][i]===1) candidate=i;
        for(let i=0; i<n; i++) {
            if(i!==candidate && (mat[candidate][i]===1 || mat[i][candidate]===0)) { console.log(-1); rl.close(); return; }
        }
        console.log(candidate);
        rl.close();
    }
});
