const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        let points = [];
        for(let i=1; i<=n; i++) {
            let [x, y] = lines[i].split(/\s+/).map(Number);
            points.push([x, y, x*x + y*y]);
        }
        
        // Max Heap of size K based on distance
        let heap = [];
        function push(item) {
            heap.push(item);
            let i = heap.length - 1;
            while (i > 0) {
                let p = Math.floor((i - 1) / 2);
                if (heap[p][2] < heap[i][2]) {
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
                    if (l < heap.length && heap[l][2] > heap[maxIdx][2]) maxIdx = l;
                    if (r < heap.length && heap[r][2] > heap[maxIdx][2]) maxIdx = r;
                    if (maxIdx !== i) {
                        [heap[i], heap[maxIdx]] = [heap[maxIdx], heap[i]];
                        i = maxIdx;
                    } else break;
                }
            }
            return top;
        }
        
        for(let p of points) {
            push(p);
            if(heap.length > k) pop();
        }
        
        let res = heap.map(p => `${p[0]} ${p[1]}`);
        console.log(res.join("\n"));
        rl.close();
    }
});
