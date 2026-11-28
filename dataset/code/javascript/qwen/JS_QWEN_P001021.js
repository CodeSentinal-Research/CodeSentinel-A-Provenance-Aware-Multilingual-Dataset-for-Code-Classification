const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        const [i, newVal] = lines[2].split(/\s+/).map(Number);
        
        if(newVal < arr[i]) {
            // No change needed for Max Heap if value decreases? 
            // Actually if value increases, we bubble up. If decreases, we might need to sink.
            // Problem says "greater than or equal to current". So only bubble up.
            arr[i] = newVal;
            let idx = i;
            while(idx > 0) {
                let p = Math.floor((idx-1)/2);
                if(arr[p] < arr[idx]) {
                    [arr[p], arr[idx]] = [arr[idx], arr[p]];
                    idx = p;
                } else break;
            }
        }
        console.log(arr.join(" "));
        rl.close();
    }
});
