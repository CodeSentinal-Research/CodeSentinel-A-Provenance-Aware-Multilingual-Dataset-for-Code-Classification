const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const ropes = lines[1].split(/\s+/).map(Number);
        
        let heap = [...ropes];
        // Build Min Heap
        for (let i = Math.floor(n / 2) - 1; i >= 0; i--) {
            let idx = i;
            while (true) {
                let l = 2 * idx + 1, r = 2 * idx + 2, minIdx = idx;
                if (l < heap.length && heap[l] < heap[minIdx]) minIdx = l;
                if (r < heap.length && heap[r] < heap[minIdx]) minIdx = r;
                if (minIdx !== idx) {
                    [heap[idx], heap[minIdx]] = [heap[minIdx], heap[idx]];
                    idx = minIdx;
                } else break;
            }
        }
        
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
        
        let cost = 0;
        while(heap.length > 1) {
            let r1 = pop();
            let r2 = pop();
            let sum = r1 + r2;
            cost += sum;
            push(sum);
        }
        console.log(cost);
        rl.close();
    }
});
