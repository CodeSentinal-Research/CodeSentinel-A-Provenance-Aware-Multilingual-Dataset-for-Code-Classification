const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let res = [];
        function solve(r, c, path) {
            if(r===n-1 && c===m-1) { res.push(path); return; }
            for(let i=1; i<=m-c; i++) solve(r, c+i, path+"H"+i);
            for(let i=1; i<=n-r; i++) solve(r+i, c, path+"V"+i);
            for(let i=1; i<=Math.min(n-r, m-c); i++) solve(r+i, c+i, path+"D"+i);
        }
        solve(0, 0, "");
        console.log(res.join("\n"));
        rl.close();
    }
});
