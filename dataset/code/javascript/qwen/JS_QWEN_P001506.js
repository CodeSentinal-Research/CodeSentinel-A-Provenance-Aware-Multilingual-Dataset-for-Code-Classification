const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0];
        const t = lines[1];
        
        let minLen = Infinity;
        let start = 0;
        let mapT = {};
        for (let c of t) mapT[c] = (mapT[c] || 0) + 1;
        
        let formed = 0;
        let windowCounts = {};
        let required = Object.keys(mapT).length;
        
        let left = 0;
        for (let right = 0; right < s.length; right++) {
            let char = s[right];
            windowCounts[char] = (windowCounts[char] || 0) + 1;
            
            if (mapT[char] && windowCounts[char] === mapT[char]) formed++;
            
            while (left <= right && formed === required) {
                char = s[left];
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                
                windowCounts[char]--;
                if (mapT[char] && windowCounts[char] < mapT[char]) formed--;
                left++;
            }
        }
        
        console.log(minLen === Infinity ? "" : s.substring(start, start + minLen));
        rl.close();
    }
});
