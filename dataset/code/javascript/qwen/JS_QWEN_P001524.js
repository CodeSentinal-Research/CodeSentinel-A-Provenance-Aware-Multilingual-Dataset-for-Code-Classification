const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0];
        const k = parseInt(lines[1]);
        
        let maxLen = 0;
        
        // Check for longest consecutive 'T's with at most k 'F' flips
        let left = 0;
        let flips = 0;
        for (let right = 0; right < s.length; right++) {
            if (s[right] === 'F') flips++;
            while (flips > k) {
                if (s[left] === 'F') flips--;
                left++;
            }
            maxLen = Math.max(maxLen, right - left + 1);
        }
        
        // Check for longest consecutive 'F's with at most k 'T' flips
        left = 0;
        flips = 0;
        for (let right = 0; right < s.length; right++) {
            if (s[right] === 'T') flips++;
            while (flips > k) {
                if (s[left] === 'T') flips--;
                left++;
            }
            maxLen = Math.max(maxLen, right - left + 1);
        }
        
        console.log(maxLen);
        rl.close();
    }
});
