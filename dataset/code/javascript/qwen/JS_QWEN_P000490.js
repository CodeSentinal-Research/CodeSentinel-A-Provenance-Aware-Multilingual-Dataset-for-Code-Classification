const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const m = parseInt(lines[0]);
        const target = lines[1].split(/\s+/).map(Number);
        const n = parseInt(lines[2]);
        let res = [], i=0, j=1;
        for(let val of target) {
            while(j<=val) {
                res.push("Push");
                if(j!==val) res.push("Pop");
                j++;
            }
        }
        console.log(res.join(" "));
        rl.close();
    }
});
