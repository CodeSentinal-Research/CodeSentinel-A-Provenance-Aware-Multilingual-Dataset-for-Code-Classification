const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0].split(' ')[0])+1) {
        const [r, c, target] = lines[0].split(/\s+/).map(Number);
        let mat = [];
        for(let i=1; i<=r; i++) mat.push(lines[i].split(/\s+/).map(Number));
        let found = false;
        for(let i=0; i<r; i++) {
            if(mat[i][0] <= target && mat[i][c-1] >= target) {
                if(mat[i].includes(target)) found = true;
            }
        }
        console.log(found ? "Found" : "Not Found");
        rl.close();
    }
});
