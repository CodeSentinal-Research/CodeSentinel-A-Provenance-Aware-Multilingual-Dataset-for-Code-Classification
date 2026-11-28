const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let A = [];
        for(let i=1; i<=n; i++) A.push(lines[i].split(/\s+/).map(Number));
        
        let isSym = true;
        for(let i=0; i<n; i++) {
            for(let j=0; j<n; j++) {
                if(A[i][j] !== A[j][i]) isSym = false;
            }
        }
        console.log(isSym ? "true" : "false");
        rl.close();
    }
});
