const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, sum] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        let curr=0, start=0;
        for(let i=0; i<n; i++) {
            curr += arr[i];
            while(curr > sum && start < i) curr -= arr[start++];
            if(curr === sum) { console.log(`${start+1} ${i+1}`); rl.close(); return; }
        }
        console.log(-1);
        rl.close();
    }
});
