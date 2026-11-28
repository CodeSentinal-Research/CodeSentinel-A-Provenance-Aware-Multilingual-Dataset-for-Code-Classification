const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [k, n] = lines[0].split(/\s+/).map(Number); // K arrays, N total elements? Or K and N per array? Problem says K and N.
        // Assuming next K lines contain sorted arrays
        let arrays = [];
        for(let i=1; i<=k; i++) {
            arrays.push(lines[i].split(/\s+/).map(Number));
        }
        
        let heap = []; // Min-heap [val, arrIdx, elemIdx]
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

        for(let i=0; i<k; i++) {
            if(arrays[i].length > 0) push([arrays[i][0], i, 0]);
        }
        
        let res = [];
        while(heap.length > 0) {
            let [val, arrIdx, elemIdx] = pop();
            res.push(val);
            if(elemIdx + 1 < arrays[arrIdx].length) {
                push([arrays[arrIdx][elemIdx+1], arrIdx, elemIdx+1]);
            }
        }
        console.log(res.join(" "));
        rl.close();
    }
});
