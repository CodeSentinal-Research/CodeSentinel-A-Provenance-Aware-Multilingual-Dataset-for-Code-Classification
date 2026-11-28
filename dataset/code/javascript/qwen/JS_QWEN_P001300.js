const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        const people = lines[1].split(/\s+/).map(Number);
        const boats = lines[2].split(/\s+/).map(Number);
        
        people.sort((a,b)=>a-b);
        boats.sort((a,b)=>a-b);
        
        let pIdx=0, bIdx=0, count=0;
        while(pIdx<n && bIdx<m) {
            if(people[pIdx]<=boats[bIdx]) {
                pIdx++; bIdx++; count++;
            } else {
                bIdx++;
            }
        }
        console.log(pIdx===n ? count : -1);
        rl.close();
    }
});
