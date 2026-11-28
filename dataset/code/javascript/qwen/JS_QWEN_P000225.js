const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let sorted = [...arr].sort((a,b)=>a-b);
        let map = {};
        sorted.forEach((v,i) => map[v]=i);
        let visited = new Array(n).fill(false);
        let swaps=0;
        for(let i=0; i<n; i++) {
            if(visited[i] || map[arr[i]]===i) continue;
            let cycleSize=0, j=i;
            while(!visited[j]) { visited[j]=true; j=map[arr[j]]; cycleSize++; }
            if(cycleSize>1) swaps += cycleSize-1;
        }
        console.log(swaps);
        rl.close();
    }
});
