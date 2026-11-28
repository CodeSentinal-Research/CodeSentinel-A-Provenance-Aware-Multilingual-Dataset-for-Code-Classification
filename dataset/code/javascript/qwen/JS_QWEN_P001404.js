const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let mat = [];
        for (let i = 1; i <= n; i++) mat.push(lines[i].split(/\s+/).map(Number));
        
        let rowMap = {}, colMap = {};
        for (let i = 0; i < n; i++) {
            let rKey = mat[i].join(',');
            rowMap[rKey] = (rowMap[rKey] || 0) + 1;
        }
        for (let j = 0; j < m; j++) {
            let col = [];
            for (let i = 0; i < n; i++) col.push(mat[i][j]);
            let cKey = col.join(',');
            colMap[cKey] = (colMap[cKey] || 0) + 1;
        }
        
        let count = 0;
        for (let key in rowMap) {
            if (colMap[key]) count += rowMap[key] * colMap[key];
        }
        console.log(count);
        rl.close();
    }
});
