const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0].split(' ')[0])+parseInt(lines[0].split(' ')[1])+1) {
        const [r1, c1, r2, c2] = lines[0].split(/\s+/).map(Number);
        let m1=[], m2=[];
        for(let i=1; i<=r1; i++) m1.push(lines[i].split(/\s+/).map(Number));
        for(let i=r1+1; i<=r1+r2; i++) m2.push(lines[i].split(/\s+/).map(Number));
        let res = Array(r1).fill(0).map(()=>Array(c2).fill(0));
        for(let i=0; i<r1; i++) {
            for(let j=0; j<c2; j++) {
                for(let k=0; k<c1; k++) res[i][j] += m1[i][k]*m2[k][j];
            }
        }
        res.forEach(row => console.log(row.join(" ")));
        rl.close();
    }
});
