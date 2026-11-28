const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0].split(' ')[0])+1) {
        const [r, c] = lines[0].split(/\s+/).map(Number);
        let mat = [];
        for(let i=1; i<=r; i++) mat.push(lines[i].split(/\s+/).map(Number));
        let top=0, bottom=r-1, left=0, right=c-1;
        let last = mat[bottom][right];
        // Rotate boundary
        let prev = mat[top][left];
        // Top row
        for(let i=left+1; i<=right; i++) { let t=mat[top][i]; mat[top][i]=prev; prev=t; }
        top++;
        // Right col
        for(let i=top; i<=bottom; i++) { let t=mat[i][right]; mat[i][right]=prev; prev=t; }
        right--;
        // Bottom row
        if(top<=bottom) {
            for(let i=right; i>=left; i--) { let t=mat[bottom][i]; mat[bottom][i]=prev; prev=t; }
            bottom--;
        }
        // Left col
        if(left<=right) {
            for(let i=bottom; i>=top; i--) { let t=mat[i][left]; mat[i][left]=prev; prev=t; }
            left++;
        }
        mat[top-1][left-1] = prev; // Fix corner
        mat.forEach(row => console.log(row.join(" ")));
        rl.close();
    }
});
