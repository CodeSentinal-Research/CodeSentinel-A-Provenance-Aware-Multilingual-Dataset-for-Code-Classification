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
            let row = [];
            for(let i=0; i<r; i++) {
                let j = d-i;
                if(j>=0 && j<c) row.push(mat[i][j]);
            }
            if(d%2===0) row.reverse();
            res.push(...row);
        }
        console.log(res.join(" "));
        rl.close();
    }
});
