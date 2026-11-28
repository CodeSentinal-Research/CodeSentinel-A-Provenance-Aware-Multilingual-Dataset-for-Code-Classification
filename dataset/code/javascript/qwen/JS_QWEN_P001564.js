const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let res = [];
        let deque = [];
        
        for (let i = 0; i < n; i++) {
            while (deque.length && nums[deque[deque.length - 1]] <= nums[i]) deque.pop();
            deque.push(i);
            
            if (i >= k - 1) {
                if (deque[0] < i - k + 1) deque.shift();
                res.push(nums[deque[0]]);
            }
        }
        
        console.log(res.join(" "));
        rl.close();
    }
});
