const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0].split(' ')[0])+1) {
        const [r, c] = lines[0].split(/\s+/).map(Number);
        let mat = [];
        for(let i=1; i<=r; i++) mat.push(lines[i].split(/\s+/).map(Number));
        let common = new Set(mat[0]);
        for(let i=1; i<r; i++) {
            let s = new Set(mat[i]);
            common = new Set([...common].filter(x => s.has(x)));
        }
        console.log([...common].join(" "));
        rl.close();
    }
});
