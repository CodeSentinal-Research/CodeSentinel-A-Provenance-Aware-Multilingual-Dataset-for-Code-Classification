const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        let mat = [];
        for(let i=1; i<=n; i++) mat.push(lines[i].split(/\s+/).map(Number));
        
        let heap = []; // Min Heap [val, r, c]
        function push(item) {
            heap.push(item);
            let i = heap.length - 1;
            while (i > 0) {
                let p = Math.floor((i - 1) / 2);
                if (heap[p][0] > heap[i][0]) {
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
                    if (l < heap.length && heap[l][0] < heap[minIdx][0]) minIdx = l;
                    if (r < heap.length && heap[r][0] < heap[minIdx][0]) minIdx = r;
                    if (minIdx !== i) {
                        [heap[i], heap[minIdx]] = [heap[minIdx], heap[i]];
                        i = minIdx;
                    } else break;
                }
            }
            return top;
        }
        
        for(let i=0; i<n; i++) push([mat[i][0], i, 0]);
        
        let res = 0;
        for(let i=0; i<k; i++) {
            let [val, r, c] = pop();
            res = val;
            if(c + 1 < n) push([mat[r][c+1], r, c+1]);
        }
        console.log(res);
        rl.close();
    }
});
