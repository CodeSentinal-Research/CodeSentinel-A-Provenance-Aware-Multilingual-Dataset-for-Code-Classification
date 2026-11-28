const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const a = lines[1].split(/\s+/).map(Number);
        const b = lines[2].split(/\s+/).map(Number);
        
        a.sort((x,y) => y-x);
        b.sort((x,y) => y-x);
        
        let heap = [];
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
        
        push([a[0]+b[0], 0, 0]);
        let visited = new Set(["0,0"]);
        let res = [];
        for(let i=0; i<k; i++) {
            let [sum, ia, ib] = pop();
            res.push(sum);
            if(ia+1 < n && !visited.has(`${ia+1},${ib}`)) {
                push([a[ia+1]+b[ib], ia+1, ib]);
                visited.add(`${ia+1},${ib}`);
            }
            if(ib+1 < n && !visited.has(`${ia},${ib+1}`)) {
                push([a[ia]+b[ib+1], ia, ib+1]);
                visited.add(`${ia},${ib+1}`);
            }
        }
        console.log(res.join(" "));
        rl.close();
    }
});
