const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let maxLen = 0;
    let map = {};
    let left = 0;
    
    for (let right = 0; right < s.length; right++) {
        if (map[s[right]] !== undefined && map[s[right]] >= left) {
            left = map[s[right]] + 1;
        }
        map[s[right]] = right;
        maxLen = Math.max(maxLen, right - left + 1);
    }
    
    console.log(maxLen);
    rl.close();
});
