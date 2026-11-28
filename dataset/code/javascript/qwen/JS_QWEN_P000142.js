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
        let top=0, bottom=r-1, left=0, right=c-1;
        while(top<=bottom && left<=right) {
            for(let i=left; i<=right; i++) res.push(mat[top][i]);
            top++;
            for(let i=top; i<=bottom; i++) res.push(mat[i][right]);
            right--;
            if(top<=bottom) {
                for(let i=right; i>=left; i--) res.push(mat[bottom][i]);
                bottom--;
            }
            if(left<=right) {
                for(let i=bottom; i>=top; i--) res.push(mat[i][left]);
                left++;
            }
        }
        console.log(res.join(" "));
        rl.close();
    }
});
