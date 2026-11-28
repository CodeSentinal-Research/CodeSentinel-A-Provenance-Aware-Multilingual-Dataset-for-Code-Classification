const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const heights = lines[1].split(/\s+/).map(Number);
        const [bricks, ladders] = lines[2].split(/\s+/).map(Number);
        
        let heap = []; // Min Heap for jumps
        function push(val) {
            heap.push(val);
            let i = heap.length - 1;
            while (i > 0) {
                let p = Math.floor((i - 1) / 2);
                if (heap[p] > heap[i]) {
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
                    let l = 2 * i + 1, r = 2 * i + 2, minIdx = i;
                    if (l < heap.length && heap[l] < heap[minIdx]) minIdx = l;
                    if (r < heap.length && heap[r] < heap[minIdx]) minIdx = r;
                    if (minIdx !== i) {
                        [heap[i], heap[minIdx]] = [heap[minIdx], heap[i]];
                        i = minIdx;
                    } else break;
                }
            }
            return top;
        }
        
        for(let i=0; i<n-1; i++) {
            let diff = heights[i+1] - heights[i];
            if(diff > 0) {
                push(diff);
                if(heap.length > ladders) {
                    bricks -= pop();
                    if(bricks < 0) { console.log(i); rl.close(); return; }
                }
            }
        }
        console.log(n-1);
        rl.close();
    }
});
