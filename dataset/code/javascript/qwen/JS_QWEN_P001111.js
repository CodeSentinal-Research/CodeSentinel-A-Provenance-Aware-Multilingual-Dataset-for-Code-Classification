const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 4) {
        const n = parseInt(lines[0]);
        const l = parseInt(lines[1]);
        let ladder = {};
        for(let i=2; i<2+l; i++) {
            const [s, e] = lines[i].split(/\s+/).map(Number);
            ladder[s] = e;
        }
        const sIdx = 2+l;
        const sn = parseInt(lines[sIdx]);
        let snake = {};
        for(let i=sIdx+1; i<sIdx+1+sn; i++) {
            const [h, t] = lines[i].split(/\s+/).map(Number);
            snake[h] = t;
        }
        
        let dist = new Array(n+1).fill(-1);
        let queue = [1];
        dist[1] = 0;
        while(queue.length > 0) {
            let u = queue.shift();
            if(u === n) { console.log(dist[u]); rl.close(); return; }
            for(let d=1; d<=6; d++) {
                let v = u + d;
                if(v > n) break;
                if(ladder[v]) v = ladder[v];
                else if(snake[v]) v = snake[v];
                
                if(dist[v] === -1) {
                    dist[v] = dist[u] + 1;
                    queue.push(v);
                }
            }
        }
        console.log(-1);
        rl.close();
    }
});
