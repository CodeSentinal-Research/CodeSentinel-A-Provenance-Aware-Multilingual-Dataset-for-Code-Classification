const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        // Max Heap of size K to find K smallest? No, Max Heap keeps largest at top.
        // To find K smallest, use Max Heap of size K. If new element < top, replace.
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
        
        for(let x of arr) {
            push(x);
            if(heap.length > k) pop();
        }
        console.log(heap.join(" "));
        rl.close();
    }
});
