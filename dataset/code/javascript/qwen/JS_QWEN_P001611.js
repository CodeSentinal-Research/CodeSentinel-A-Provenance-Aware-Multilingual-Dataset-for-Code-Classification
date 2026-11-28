const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let deque = [];
        let prefix = [0];
        for (let x of nums) prefix.push(prefix[prefix.length - 1] + x);
        
        let minLen = Infinity;
        for (let i = 0; i <= n; i++) {
            while (deque.length && prefix[deque[deque.length - 1]] >= prefix[i]) deque.pop();
            deque.push(i);
            
            while (deque.length && prefix[i] - prefix[deque[0]] >= k) {
                minLen = Math.min(minLen, i - deque.shift());
            }
        }
        console.log(minLen === Infinity ? -1 : minLen);
        rl.close();
    }
});
