const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [target, startFuel] = lines[0].split(/\s+/).map(Number);
        const n = parseInt(lines[1]);
        let stations = [];
        for(let i=2; i<2+n; i++) stations.push(lines[i].split(/\s+/).map(Number));
        
        stations.sort((a,b)=>a[0]-b[0]);
        stations.push([target, 0]);
        
        let heap = [];
        let fuel = startFuel, stops=0, prev=0;
        
        for(let [pos, f] of stations) {
            let dist = pos-prev;
            while(fuel<dist) {
                if(heap.length===0) { console.log(-1); rl.close(); return; }
                fuel += heap.pop(); // Max heap simulated by sort
                stops++;
            }
            fuel -= dist;
            heap.push(f);
            heap.sort((a,b)=>a-b);
            prev = pos;
        }
        console.log(stops);
        rl.close();
    }
});
