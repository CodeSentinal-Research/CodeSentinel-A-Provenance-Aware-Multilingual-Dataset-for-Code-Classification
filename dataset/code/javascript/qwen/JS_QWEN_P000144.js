const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0].split(' ')[0])+1) {
        const [r, c] = lines[0].split(/\s+/).map(Number);
        let mat = [];
        for(let i=1; i<=r; i++) mat.push(lines[i].split(/\s+/).map(Number));
        let rows = new Set(), cols = new Set();
        for(let i=0; i<r; i++) {
            for(let j=0; j<c; j++) {
                if(mat[i][j]===0) { rows.add(i); cols.add(j); }
            }
        }
        for(let i=0; i<r; i++) {
            for(let j=0; j<c; j++) {
                if(rows.has(i) || cols.has(j)) mat[i][j]=0;
            }
        }
        mat.forEach(row => console.log(row.join(" ")));
        rl.close();
    }
});
