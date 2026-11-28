const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, k, capital] = lines[0].split(/\s+/).map(Number);
        let projects = [];
        for(let i=1; i<=n; i++) projects.push(lines[i].split(/\s+/).map(Number));
        
        projects.sort((a,b)=>a[0]-b[0]);
        
        let heap = [], idx=0;
        for(let i=0; i<k; i++) {
            while(idx<n && projects[idx][0]<=capital) {
                heap.push(projects[idx][1]);
                idx++;
            }
            if(heap.length===0) break;
            heap.sort((a,b)=>b-a);
            capital+=heap.shift();
        }
        console.log(capital);
        rl.close();
    }
});
