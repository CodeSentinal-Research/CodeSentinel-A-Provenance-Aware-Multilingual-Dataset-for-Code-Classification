const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const queries = lines[0].split(/\s+/);
        const pattern = lines[1];
        let res = [];
        for(let q of queries) {
            let j=0;
            for(let i=0; i<q.length; i++) {
                if(q[i] === pattern[j]) j++;
                else if(q[i] >= 'A' && q[i] <= 'Z') { j=-1; break; }
            }
            res.push(j === pattern.length ? "true" : "false");
        }
        console.log(res.join(" "));
        rl.close();
    }
});
