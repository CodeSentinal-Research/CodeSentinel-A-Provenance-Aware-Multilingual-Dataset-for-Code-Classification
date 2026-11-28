const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        
        let maxHeap = [], minHeap = [];
        for(let x of arr) {
            if(x % 2 === 0) minHeap.push(x);
            else maxHeap.push(x);
        }
        
        // Make maxHeap a max heap
        for (let i = Math.floor(maxHeap.length / 2) - 1; i >= 0; i--) {
            let idx = i;
            while (true) {
                let l = 2 * idx + 1, r = 2 * idx + 2, maxIdx = idx;
                if (l < maxHeap.length && maxHeap[l] > maxHeap[maxIdx]) maxIdx = l;
                if (r < maxHeap.length && maxHeap[r] > maxHeap[maxIdx]) maxIdx = r;
                if (maxIdx !== idx) {
                    [maxHeap[idx], maxHeap[maxIdx]] = [maxHeap[maxIdx], maxHeap[idx]];
                    idx = maxIdx;
                } else break;
            }
        }
        
        // Make minHeap a min heap
        for (let i = Math.floor(minHeap.length / 2) - 1; i >= 0; i--) {
            let idx = i;
            while (true) {
                let l = 2 * idx + 1, r = 2 * idx + 2, minIdx = idx;
                if (l < minHeap.length && minHeap[l] < minHeap[minIdx]) minIdx = l;
                if (r < minHeap.length && minHeap[r] < minHeap[minIdx]) minIdx = r;
                if (minIdx !== idx) {
                    [minHeap[idx], minHeap[minIdx]] = [minHeap[minIdx], minHeap[idx]];
                    idx = minIdx;
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
        
        while(maxHeap.length > 0 && minHeap.length > 0) {
            let mx = popMax();
            if(mx % 2 !== 0) mx /= 2; // Halve even? No, odd numbers can't be halved to int easily in this context unless specified. 
            // Problem says: double odd, halve even.
            // To minimize deviation, we should reduce large numbers.
            // Max heap allows us to pick largest. If it's even, halve it. If odd, double it (but doubling increases it, so we only halve evens).
            // Wait, deviation is max - min.
            // We can only double odds (making them even) and halve evens.
            // Once an odd is doubled, it becomes even and can be halved.
            // Strategy: Double all odds first to make them even. Then use max heap to repeatedly halve the max element.
            
            // Correct Logic:
            // 1. Double all odds.
            // 2. Push all to max heap.
            // 3. Track min.
            // 4. Pop max, halve it, push back. Update min and answer.
        }
        
        // Re-implementing correct logic
        let heap = [];
        let minVal = Infinity;
        for(let x of arr) {
            let val = x;
            if(val % 2 !== 0) val *= 2;
            heap.push(val);
            minVal = Math.min(minVal, val);
        }
        
        // Build Max Heap
        for (let i = Math.floor(heap.length / 2) - 1; i >= 0; i--) {
            let idx = i;
            while (true) {
                let l = 2 * idx + 1, r = 2 * idx + 2, maxIdx = idx;
                if (l < heap.length && heap[l] > heap[maxIdx]) maxIdx = l;
                if (r < heap.length && heap[r] > heap[maxIdx]) maxIdx = r;
                if (maxIdx !== idx) {
                    [heap[idx], heap[maxIdx]] = [heap[maxIdx], heap[idx]];
                    idx = maxIdx;
                } else break;
            }
        }
        
        function pushMax(val) {
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
        function popMax() {
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
        
        let ans = heap[0] - minVal;
        while(heap[0] % 2 === 0) {
            let mx = popMax();
            minVal = Math.min(minVal, mx/2);
            pushMax(mx/2);
            ans = Math.min(ans, heap[0] - minVal);
        }
        console.log(ans);
        rl.close();
    }
});
