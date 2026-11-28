const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, dStr] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        const d = parseInt(dStr);
        let l=0, r=1;
        while(r<n) {
            if(arr[r]-arr[l]===d) { console.log("Yes"); rl.close(); return; }
            else if(arr[r]-arr[l]<d) r++;
            else l++;
            if(l===r) r++;
        }
        console.log("No");
        rl.close();
    }
});
