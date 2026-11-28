const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0];
        const k = parseInt(lines[1]);
        
        let maxLen = 0;
        let counts = new Array(26).fill(0);
        let left = 0;
        let maxCount = 0;
        
        for (let right = 0; right < s.length; right++) {
            let idx = s.charCodeAt(right) - 65;
            counts[idx]++;
            maxCount = Math.max(maxCount, counts[idx]);
            
            while ((right - left + 1) - maxCount > k) {
                counts[s.charCodeAt(left) - 65]--;
                left++;
            }
            
            maxLen = Math.max(maxLen, right - left + 1);
        }
        
        console.log(maxLen);
        rl.close();
    }
});
