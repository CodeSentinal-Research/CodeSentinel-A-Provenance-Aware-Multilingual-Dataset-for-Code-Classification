const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let heap = []; // Max-heap storing [value, index]
        function push(item) {
            heap.push(item);
            let i = heap.length - 1;
            while (i > 0) {
                let p = Math.floor((i - 1) / 2);
                if (heap[p][0] < heap[i][0]) {
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
                    if (l < heap.length && heap[l][0] > heap[maxIdx][0]) maxIdx = l;
                    if (r < heap.length && heap[r][0] > heap[maxIdx][0]) maxIdx = r;
                    if (maxIdx !== i) {
                        [heap[i], heap[maxIdx]] = [heap[maxIdx], heap[i]];
                        i = maxIdx;
                    } else break;
                }
            }
            return top;
        }
        
        let res = [];
        for(let i=0; i<n; i++) {
            push([nums[i], i]);
            while(heap[0][1] <= i - k) pop(); // Remove out of window
            if(i >= k - 1) res.push(heap[0][0]);
        }
        console.log(res.join(" "));
        rl.close();
    }
});
