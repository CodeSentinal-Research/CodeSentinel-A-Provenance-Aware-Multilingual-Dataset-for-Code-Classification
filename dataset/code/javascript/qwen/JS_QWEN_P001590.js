const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [n, budget] = lines[0].split(/\s+/).map(Number);
        const chargeTimes = lines[1].split(/\s+/).map(Number);
        const runningCosts = lines[2].split(/\s+/).map(Number);
        
        let maxRobots = 0;
        let sumRunning = 0;
        let deque = [];
        let left = 0;
        
        for (let right = 0; right < n; right++) {
            sumRunning += runningCosts[right];
            
            while (deque.length && chargeTimes[deque[deque.length - 1]] <= chargeTimes[right]) deque.pop();
            deque.push(right);
            
            while (left <= right && chargeTimes[deque[0]] + (right - left + 1) * sumRunning > budget) {
                sumRunning -= runningCosts[left];
                if (deque[0] === left) deque.shift();
                left++;
            }
            
            maxRobots = Math.max(maxRobots, right - left + 1);
        }
        
        console.log(maxRobots);
        rl.close();
    }
});
