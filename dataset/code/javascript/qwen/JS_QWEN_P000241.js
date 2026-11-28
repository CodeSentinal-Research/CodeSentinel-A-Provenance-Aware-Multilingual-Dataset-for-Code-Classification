const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        let mat = [];
        for(let i=1; i<=n; i++) mat.push(lines[i].split(/\s+/).map(Number));
        for(let i=0; i<n; i++) {
            let minRow = Math.min(...mat[i]);
            let colIdx = mat[i].indexOf(minRow);
            let isMaxCol = true;
            for(let k=0; k<n; k++) if(mat[k][colIdx] > minRow) isMaxCol = false;
            if(isMaxCol) { console.log(minRow); rl.close(); return; }
        }
        console.log("No Saddle Point");
        rl.close();
    }
});
