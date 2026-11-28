const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        const k = parseInt(lines[2]);
        let dp = new Array(n).fill(-Infinity);
        dp[0] = nums[0];
        let deque = [0];
        for(let i=1; i<n; i++) {
            while(deque.length && deque[0] < i-k) deque.shift();
            dp[i] = Math.max(dp[i], (dp[deque[0]]||0) + nums[i]);
            while(deque.length && dp[deque[deque.length-1]] <= dp[i]) deque.pop();
            deque.push(i);
        }
        console.log(Math.max(...dp));
        rl.close();
    }
});
