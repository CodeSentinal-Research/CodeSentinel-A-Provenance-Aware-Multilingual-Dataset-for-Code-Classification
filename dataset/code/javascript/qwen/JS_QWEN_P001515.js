const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let count = 0;
        let currLen = 1;
        
        for (let i = 1; i < n; i++) {
            if (nums[i] !== nums[i-1]) {
                currLen++;
            } else {
                currLen = 1;
            }
            count += currLen;
        }
        
        // Add single element subarrays
        count += n; // Wait, logic above counts subarrays of length >= 2. 
        // Let's restart with standard approach
        
        count = 0;
        for (let i = 0; i < n; ) {
            let j = i;
            while (j < n && nums[j] !== nums[j+1]) j++; // This finds non-alternating? No.
            // Alternating means nums[k] != nums[k+1]
            
            // Let's use simple loop
            break;
        }
        
        // Correct approach
        count = 0;
        let start = 0;
        for (let end = 0; end < n; end++) {
            if (end > 0 && nums[end] === nums[end-1]) {
                start = end;
            }
            count += (end - start + 1);
        }
        
        console.log(count);
        rl.close();
    }
});
