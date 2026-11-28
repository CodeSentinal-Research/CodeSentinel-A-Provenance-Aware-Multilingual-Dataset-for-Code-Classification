const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        let maxHeap = [], minHeap = [];
        let res = [];
        
        function pushMax(val) {
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
        function popMax() {
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
        
        function pushMin(val) {
            minHeap.push(val);
            let i = minHeap.length - 1;
            while (i > 0) {
                let p = Math.floor((i - 1) / 2);
                if (minHeap[p] > minHeap[i]) {
                    [minHeap[p], minHeap[i]] = [minHeap[i], minHeap[p]];
                    i = p;
                } else break;
            }
        }
        function popMin() {
            let top = minHeap[0];
            let last = minHeap.pop();
            if (minHeap.length > 0) {
                minHeap[0] = last;
                let i = 0;
                while (true) {
                    let l = 2 * i + 1, r = 2 * i + 2, minIdx = i;
                    if (l < minHeap.length && minHeap[l] < minHeap[minIdx]) minIdx = l;
                    if (r < minHeap.length && minHeap[r] < minHeap[minIdx]) minIdx = r;
                    if (minIdx !== i) {
                        [minHeap[i], minHeap[minIdx]] = [minHeap[minIdx], minHeap[i]];
                        i = minIdx;
                    } else break;
                }
            }
            return top;
        }

        for (let num of nums) {
            if (maxHeap.length === 0 || num <= maxHeap[0]) pushMax(num);
            else pushMin(num);
            
            if (maxHeap.length > minHeap.length + 1) pushMin(popMax());
            else if (minHeap.length > maxHeap.length) pushMax(popMin());
            
            let median;
            if (maxHeap.length > minHeap.length) median = maxHeap[0];
            else median = (maxHeap[0] + minHeap[0]) / 2;
            res.push(median.toFixed(1));
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
