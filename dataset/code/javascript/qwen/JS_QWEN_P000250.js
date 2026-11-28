const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        let mat = [];
        for(let i=1; i<=n; i++) mat.push(lines[i].split(/\s+/).map(Number));
        function det(m) {
            if(m.length===1) return m[0][0];
            if(m.length===2) return m[0][0]*m[1][1]-m[0][1]*m[1][0];
            let d=0;
            for(let i=0; i<m.length; i++) {
                let sub = m.slice(1).map(row=>[...row.slice(0,i), ...row.slice(i+1)]);
                d += (i%2===0?1:-1)*m[0][i]*det(sub);
            }
            return d;
        }
        console.log(det(mat));
        rl.close();
    }
});
