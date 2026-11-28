const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        const k = parseInt(lines[2]);
        let deque = [];
        let res = [];
        for(let i=0; i<n; i++) {
            while(deque.length && nums[deque[deque.length-1]] <= nums[i]) deque.pop();
            deque.push(i);
            if(deque[0] <= i-k) deque.shift();
            if(i>=k-1) res.push(nums[deque[0]]);
        }
        console.log(res.join(" "));
        rl.close();
    }
});
