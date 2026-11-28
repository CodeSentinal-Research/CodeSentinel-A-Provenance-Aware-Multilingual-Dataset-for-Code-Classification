const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, kStr] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        const k = parseInt(kStr);
        let missing = 0, i=0, curr=1;
        while(missing < k) {
            if(i<n && arr[i]===curr) i++;
            else missing++;
            if(missing===k) { console.log(curr); rl.close(); return; }
            curr++;
        }
        rl.close();
    }
});
