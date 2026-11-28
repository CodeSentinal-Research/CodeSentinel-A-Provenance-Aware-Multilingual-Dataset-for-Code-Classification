const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let A = [], B = [];
        for (let i = 1; i <= n; i++) A.push(lines[i].split(/\s+/).map(Number));
        for (let i = n + 1; i <= n + m; i++) B.push(lines[i].split(/\s+/).map(Number));
        
        let res = [];
        let i = 0, j = 0;
        while (i < n && j < m) {
            if (A[i][1] <= B[j][0]) {
                res.push([Math.max(A[i][0], B[j][0]), Math.min(A[i][1], B[j][1])]);
            }
            if (A[i][1] < B[j][1]) i++;
            else j++;
        }
        // Filter empty intersections
        res = res.filter(r => r[0] < r[1]);
        console.log(res.map(r => r.join(" ")).join("\n"));
        rl.close();
    }
});
