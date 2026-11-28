const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const A = lines[1].split(/\s+/).map(Number);
        const B = lines[2].split(/\s+/).map(Number);
        
        let setA = new Set(), setB = new Set();
        let res = [];
        let common = 0;
        for (let i = 0; i < n; i++) {
            setA.add(A[i]);
            setB.add(B[i]);
            common = setA.intersection ? setA.intersection(setB).size : [...setA].filter(x => setB.has(x)).length;
            res.push(common);
        }
        console.log(res.join(" "));
        rl.close();
    }
});
