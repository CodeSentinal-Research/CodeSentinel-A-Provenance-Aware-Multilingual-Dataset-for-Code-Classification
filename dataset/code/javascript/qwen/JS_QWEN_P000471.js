const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0].split(' ')[0])+1) {
        const [r, c] = lines[0].split(/\s+/).map(Number);
        let mat = [];
        for(let i=1; i<=r; i++) mat.push(lines[i].split(/\s+/).map(Number));
        let peak = mat[0][0];
        for(let i=0; i<r; i++) {
            for(let j=0; j<c; j++) {
                let isPeak = true;
                if(i>0 && mat[i-1][j]>=mat[i][j]) isPeak=false;
                if(i<r-1 && mat[i+1][j]>=mat[i][j]) isPeak=false;
                if(j>0 && mat[i][j-1]>=mat[i][j]) isPeak=false;
                if(j<c-1 && mat[i][j+1]>=mat[i][j]) isPeak=false;
                if(isPeak) { console.log(mat[i][j]); rl.close(); return; }
            }
        }
        rl.close();
    }
});
