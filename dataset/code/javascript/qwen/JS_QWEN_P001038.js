const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 4) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const capital = lines[1].split(/\s+/).map(Number);
        const profit = lines[2].split(/\s+/).map(Number);
        const w = parseInt(lines[3]);
        
        let projects = [];
        for(let i=0; i<n; i++) projects.push([capital[i], profit[i]]);
        projects.sort((a,b) => a[0] - b[0]);
        
        let maxHeap = [];
        function push(val) {
            maxHeap.push(val);
            let i = maxHeap.length - 1;
            while (i > 0) {
                let p = Math.floor((i - 1) / 2);
                if (maxHeap[p] < maxHeap[i]) {
                    [maxHeap[p], maxHeap[i]] = [maxHeap[i], maxHeap[p]];
                    i = p;
                } else break;
            }
        }
        function pop() {
            let top = maxHeap[0];
            let last = maxHeap.pop();
            if (maxHeap.length > 0) {
                maxHeap[0] = last;
                let i = 0;
                while (true) {
                    let l = 2 * i + 1, r = 2 * i + 2, maxIdx = i;
                    if (l < maxHeap.length && maxHeap[l] > maxHeap[maxIdx]) maxIdx = l;
                    if (r < maxHeap.length && maxHeap[r] > maxHeap[maxIdx]) maxIdx = r;
                    if (maxIdx !== i) {
                        [maxHeap[i], maxHeap[maxIdx]] = [maxHeap[maxIdx], maxHeap[i]];
                        i = maxIdx;
                    } else break;
                }
            }
            return top;
        }
        
        let idx = 0;
        for(let i=0; i<k; i++) {
            while(idx < n && projects[idx][0] <= w) {
                push(projects[idx][1]);
                idx++;
            }
            if(maxHeap.length === 0) break;
            w += pop();
        }
        console.log(w);
        rl.close();
    }
});
