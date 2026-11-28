const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let maxLen = 0;
    let map = {};
    let left = 0;
    
    for (let right = 0; right < s.length; right++) {
        map[s[right]] = (map[s[right]] || 0) + 1;
        
        while (Object.keys(map).length > 2) {
            map[s[left]]--;
            if (map[s[left]] === 0) delete map[s[left]];
            left++;
        }
        
        maxLen = Math.max(maxLen, right - left + 1);
    }
    
    console.log(maxLen);
    rl.close();
});
