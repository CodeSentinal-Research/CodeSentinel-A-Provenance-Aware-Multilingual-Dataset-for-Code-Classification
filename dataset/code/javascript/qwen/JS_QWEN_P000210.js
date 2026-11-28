const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 4) {
        const [n1, n2, n3] = lines[0].split(/\s+/).map(Number);
        const a1 = lines[1].split(/\s+/).map(Number);
        const a2 = lines[2].split(/\s+/).map(Number);
        const a3 = lines[3].split(/\s+/).map(Number);
        let s1=new Set(a1), s2=new Set(a2), s3=new Set(a3);
        let res = [];
        for(let x of s1) if(s2.has(x) && s3.has(x)) res.push(x);
        console.log(res.join(" "));
        rl.close();
    }
});
