const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let count = {};
    for(let c of s) count[c] = (count[c]||0) + 1;
    
    let heap = [];
    Object.keys(count).forEach(c => {
        heap.push([c, count[c]]);
    });
    
    // Max Heap by frequency
    function push(item) {
        heap.push(item);
        let i = heap.length - 1;
        while (i > 0) {
            let p = Math.floor((i - 1) / 2);
            if (heap[p][1] < heap[i][1]) {
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
                if (l < heap.length && heap[l][1] > heap[maxIdx][1]) maxIdx = l;
                if (r < heap.length && heap[r][1] > heap[maxIdx][1]) maxIdx = r;
                if (maxIdx !== i) {
                    [heap[i], heap[maxIdx]] = [heap[maxIdx], heap[i]];
                    i = maxIdx;
                } else break;
            }
        }
        return top;
    }
    
    // Re-build heap properly
    heap = [];
    Object.keys(count).forEach(c => push([c, count[c]]));
    
    let res = "";
    let prev = null;
    while(heap.length > 0) {
        let curr = pop();
        res += curr[0];
        curr[1]--;
        if(prev && prev[1] > 0) push(prev);
        prev = curr[1] > 0 ? curr : null;
    }
    
    console.log(res.length === s.length ? res : "IMPOSSIBLE");
    rl.close();
});
