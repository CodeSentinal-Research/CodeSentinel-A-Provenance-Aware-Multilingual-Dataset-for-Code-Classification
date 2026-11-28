const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2*parseInt(lines[0].split(' ')[0])+1) {
        const [r, c] = lines[0].split(/\s+/).map(Number);
        let m1=[], m2=[];
        for(let i=1; i<=r; i++) m1.push(lines[i].split(/\s+/).map(Number));
        for(let i=r+1; i<=2*r; i++) m2.push(lines[i].split(/\s+/).map(Number));
        let res = [];
        for(let i=0; i<r; i++) {
            let row = [];
            for(let j=0; j<c; j++) row.push(m1[i][j]+m2[i][j]);
            res.push(row.join(" "));
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
