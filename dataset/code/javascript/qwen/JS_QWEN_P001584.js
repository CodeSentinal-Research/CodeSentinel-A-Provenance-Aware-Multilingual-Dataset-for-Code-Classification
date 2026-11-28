const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0];
        const k = parseInt(lines[1]);
        
        let maxLen = 0;
        let vowelCount = 0;
        let left = 0;
        let vowels = new Set(['a', 'e', 'i', 'o', 'u']);
        
        for (let right = 0; right < s.length; right++) {
            if (vowels.has(s[right])) vowelCount++;
            
            while (vowelCount > k) {
                if (vowels.has(s[left])) vowelCount--;
                left++;
            }
            
            maxLen = Math.max(maxLen, right - left + 1);
        }
        
        console.log(maxLen);
        rl.close();
    }
});
