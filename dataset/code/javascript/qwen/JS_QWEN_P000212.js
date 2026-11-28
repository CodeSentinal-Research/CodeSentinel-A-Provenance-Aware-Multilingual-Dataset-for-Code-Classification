const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [size, n] = lines[0].split(/\s+/).map(Number);
        const bed = lines[1].split(/\s+/).map(Number);
        let count = 0;
        for(let i=0; i<size; i++) {
            if(bed[i]===0 && (i===0 || bed[i-1]===0) && (i===size-1 || bed[i+1]===0)) {
                bed[i]=1; count++;
            }
        }
        console.log(count >= n ? "Yes" : "No");
        rl.close();
    }
});
