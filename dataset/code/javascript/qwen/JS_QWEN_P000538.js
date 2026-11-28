const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        const k = parseInt(lines[2]);
        let prefix = [0];
        for(let x of nums) prefix.push(prefix[prefix.length-1]+x);
        let deque = [];
        let minLen = Infinity;
        for(let i=0; i<prefix.length; i++) {
            while(deque.length && prefix[deque[deque.length-1]] >= prefix[i]) deque.pop();
            deque.push(i);
            while(prefix[i] - prefix[deque[0]] >= k) {
                minLen = Math.min(minLen, i-deque.shift());
            }
        }
        console.log(minLen===Infinity ? -1 : minLen);
        rl.close();
    }
});
