const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0].split(' ')[1])+2) {
        const [r, c, target] = lines[0].split(/\s+/).map(Number);
        let mat = [];
        for(let i=1; i<=r; i++) mat.push(lines[i].split(/\s+/).map(Number));
        let i=0, j=c-1;
        let found = false;
        while(i<r && j>=0) {
            if(mat[i][j]===target) { found=true; break; }
            else if(mat[i][j]>target) j--;
            else i++;
        }
        console.log(found ? "Found" : "Not Found");
        rl.close();
    }
});
