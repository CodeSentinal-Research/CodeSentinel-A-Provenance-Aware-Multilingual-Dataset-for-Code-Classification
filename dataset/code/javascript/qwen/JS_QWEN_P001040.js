const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const speed = lines[1].split(/\s+/).map(Number);
        const eff = lines[2].split(/\s+/).map(Number);
        
        let engineers = [];
        for(let i=0; i<n; i++) engineers.push([eff[i], speed[i]]);
        engineers.sort((a,b) => b[0] - a[0]);
        
        let heap = []; // Min Heap for speed
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
        
        let sumSpeed = 0, maxPerf = 0;
        for(let [e, s] of engineers) {
            push(s);
            sumSpeed += s;
            if(heap.length > k) sumSpeed -= pop();
            maxPerf = Math.max(maxPerf, sumSpeed * e);
        }
        console.log(maxPerf);
        rl.close();
    }
});
