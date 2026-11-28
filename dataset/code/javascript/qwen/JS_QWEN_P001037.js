const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const tasks = lines[1].split('');
        const k = parseInt(lines[2]);
        
        let count = {};
        for(let t of tasks) count[t] = (count[t]||0) + 1;
        
        let heap = [];
        Object.keys(count).forEach(c => {
            heap.push([c, count[c]]);
        });
        
        // Max Heap
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
        
        // Re-build
        heap = [];
        Object.keys(count).forEach(c => push([c, count[c]]));
        
        let time = 0;
        let queue = []; // Cooldown queue [task, remainingCount, readyTime]
        
        while(heap.length > 0 || queue.length > 0) {
            time++;
            if(queue.length > 0 && queue[0][2] === time) {
                let [t, cnt, _] = queue.shift();
                push([t, cnt]);
            }
            
            if(heap.length > 0) {
                let [task, cnt] = pop();
                cnt--;
                if(cnt > 0) queue.push([task, cnt, time + k + 1]);
            }
        }
        console.log(time);
        rl.close();
    }
});
