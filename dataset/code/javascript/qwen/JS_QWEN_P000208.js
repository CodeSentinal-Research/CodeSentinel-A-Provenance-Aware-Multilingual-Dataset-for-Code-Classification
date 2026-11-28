const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0].split(' ')[0])+1) {
        const [r, c] = lines[0].split(/\s+/).map(Number);
        let mat = [];
        for(let i=1; i<=r; i++) mat.push(lines[i].split(/\s+/).map(Number));
        let res = [];
        for(let d=0; d<r+c-1; d++) {
            let row = [], rIdx=d, cIdx=0;
            if(d>=c) { cIdx=d-c+1; rIdx=c-1; } // Adjusted logic for standard diagonal
            // Standard diagonal traversal usually goes top-right to bottom-left or vice versa
            // Let's do simple diagonal collection
            let temp = [];
            for(let i=0; i<r; i++) {
                for(let j=0; j<c; j++) {
                    if(i+j === d) temp.push(mat[i][j]);
                }
            }
            if(d%2===0) temp.reverse(); 
            res.push(...temp);
        }
        console.log(res.join(" "));
        rl.close();
    }
});
