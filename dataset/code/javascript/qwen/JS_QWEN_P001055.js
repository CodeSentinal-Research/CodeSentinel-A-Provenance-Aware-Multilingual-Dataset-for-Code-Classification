const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const target = parseInt(lines[0]);
        const startFuel = parseInt(lines[1]);
        const n = parseInt(lines[2]);
        let stations = [];
        for(let i=3; i<3+n; i++) {
            let [pos, fuel] = lines[i].split(/\s+/).map(Number);
            stations.push([pos, fuel]);
        }
        
        let heap = [];
        function push(val) {
            heap.push(val);
            let i = heap.length - 1;
            while (i > 0) {
                let p = Math.floor((i - 1) / 2);
                if (heap[p] < heap[i]) {
                    [heap[p], heap[i]] = [heap[i], heap[p]];
                    i = p;
                } else break;
            }
        }
        function pop() {
            let top = heap[0];
            let last = heap.pop();
            if (heap.length > 0) {
                heap[0] = last;
                let i = 0;
                while (true) {
                    let l = 2 * i + 1, r = 2 * i + 2, maxIdx = i;
                    if (l < heap.length && heap[l] > heap[maxIdx]) maxIdx = l;
                    if (r < heap.length && heap[r] > heap[maxIdx]) maxIdx = r;
                    if (maxIdx !== i) {
                        [heap[i], heap[maxIdx]] = [heap[maxIdx], heap[i]];
                        i = maxIdx;
                    } else break;
                }
            }
            return top;
        }
        
        stations.push([target, 0]);
        let fuel = startFuel, stops = 0, prevPos = 0;
        for(let [pos, f] of stations) {
            let dist = pos - prevPos;
            while(fuel < dist) {
                if(heap.length === 0) { console.log(-1); rl.close(); return; }
                fuel += pop();
                stops++;
            }
            fuel -= dist;
            push(f);
            prevPos = pos;
        }
        console.log(stops);
        rl.close();
    }
});
