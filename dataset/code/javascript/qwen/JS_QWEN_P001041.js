const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const quality = lines[1].split(/\s+/).map(Number);
        const wage = lines[2].split(/\s+/).map(Number);
        
        let workers = [];
        for(let i=0; i<n; i++) workers.push([wage[i]/quality[i], quality[i], wage[i]]);
        workers.sort((a,b) => a[0] - b[0]);
        
        let heap = []; // Max Heap for quality
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
        
        let sumQ = 0, minCost = Infinity;
        for(let [ratio, q, w] of workers) {
            push(q);
            sumQ += q;
            if(heap.length > k) sumQ -= pop();
            if(heap.length === k) minCost = Math.min(minCost, sumQ * ratio);
        }
        console.log(minCost.toFixed(5));
        rl.close();
    }
});
