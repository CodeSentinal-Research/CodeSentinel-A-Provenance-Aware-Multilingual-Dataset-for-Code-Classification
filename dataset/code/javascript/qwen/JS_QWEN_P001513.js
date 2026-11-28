const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let distinctSet = new Set(nums);
        let totalDistinct = distinctSet.size;
        
        let count = 0;
        let windowMap = {};
        let left = 0;
        let distinctInWindow = 0;
        
        for (let right = 0; right < n; right++) {
            windowMap[nums[right]] = (windowMap[nums[right]] || 0) + 1;
            if (windowMap[nums[right]] === 1) distinctInWindow++;
            
            while (distinctInWindow === totalDistinct) {
                count += (n - right);
                windowMap[nums[left]]--;
                if (windowMap[nums[left]] === 0) distinctInWindow--;
                left++;
            }
        }
        
        console.log(count);
        rl.close();
    }
});
