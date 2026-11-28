const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        let count = {};
        for(let x of arr) count[x] = (count[x]||0) + 1;
        
        let heap = [];
        Object.keys(count).forEach(key => {
            heap.push([parseInt(key), count[key]]);
        });
        
        // Min Heap by frequency
        function push(item) {
            heap.push(item);
            let i = heap.length - 1;
            while (i > 0) {
                let p = Math.floor((i - 1) / 2);
                if (heap[p][1] > heap[i][1]) {
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
                    if (l < heap.length && heap[l][1] < heap[minIdx][1]) minIdx = l;
                    if (r < heap.length && heap[r][1] < heap[minIdx][1]) minIdx = r;
                    if (minIdx !== i) {
                        [heap[i], heap[minIdx]] = [heap[minIdx], heap[i]];
                        i = minIdx;
                    } else break;
                }
            }
            return top;
        }
        
        // Re-build
        heap = [];
        Object.keys(count).forEach(key => push([parseInt(key), count[key]]));
        
        while(k > 0 && heap.length > 0) {
            let [val, freq] = pop();
            let remove = Math.min(k, freq);
            k -= remove;
            if(freq - remove > 0) push([val, freq-remove]);
        }
        console.log(heap.length);
        rl.close();
    }
});
