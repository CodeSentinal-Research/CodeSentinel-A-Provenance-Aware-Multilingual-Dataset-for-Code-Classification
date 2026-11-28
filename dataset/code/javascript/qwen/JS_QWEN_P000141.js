const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        let mat = [];
        for(let i=1; i<=n; i++) mat.push(lines[i].split(/\s+/).map(Number));
        // Transpose then reverse rows
        for(let i=0; i<n; i++) {
            for(let j=i; j<n; j++) {
                [mat[i][j], mat[j][i]] = [mat[j][i], mat[i][j]];
            }
        }
        mat.forEach(row => row.reverse());
        mat.forEach(row => console.log(row.join(" ")));
        rl.close();
    }
});
