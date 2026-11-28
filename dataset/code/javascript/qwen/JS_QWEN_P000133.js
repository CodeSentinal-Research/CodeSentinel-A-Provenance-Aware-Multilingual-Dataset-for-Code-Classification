const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let temp = [...arr];
        let res = new Array(n);
        let i=0, j=n-1, k=0;
        while(i<=j) {
            if(k%2===0) res[k++] = temp[j--];
            else res[k++] = temp[i++];
        }
        // Note: Problem asks for max-min alternating, usually implies sorted input
        // Simple implementation for sorted input
        console.log(res.join(" "));
        rl.close();
    }
});
