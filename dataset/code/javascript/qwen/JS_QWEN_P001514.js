const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let maxLen = 0;
    let left = 0;
    let hasPair = false;
    
    for (let right = 1; right < s.length; right++) {
        if (s[right] === s[right-1]) {
            if (hasPair) {
                // Move left to break the previous pair
                left = right - 1;
            }
            hasPair = true;
        } else {
            hasPair = false;
        }
        maxLen = Math.max(maxLen, right - left + 1);
    }
    
    // Handle single char or empty string
    if (s.length <= 1) maxLen = s.length;
    
    console.log(maxLen);
    rl.close();
});
