const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 1) {
        const q = parseInt(lines[0]);
        let heap = [];
        let added = new Set();
        let next = 1;
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
        
        let res = [];
        for(let i=1; i<=q; i++) {
            const parts = lines[i].split(' ');
            if(parts[0] === 'add') {
                let val = parseInt(parts[1]);
                if(!added.has(val)) {
                    push(val);
                    added.add(val);
                }
            } else {
                while(heap.length > 0 && added.has(heap[0])) {
                     // Clean up if needed, but logic above handles it
                }
                let val = pop();
                added.delete(val);
                res.push(val);
            }
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
