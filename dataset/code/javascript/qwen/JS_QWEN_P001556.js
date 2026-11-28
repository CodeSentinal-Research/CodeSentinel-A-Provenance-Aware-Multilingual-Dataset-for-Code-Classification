const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const text = lines[0];
        const pattern = lines[1];
        
        let mapP = {};
        for (let c of pattern) mapP[c] = (mapP[c] || 0) + 1;
        
        let windowCounts = {};
        let formed = 0;
        let required = Object.keys(mapP).length;
        let count = 0;
        
        let left = 0;
        for (let right = 0; right < text.length; right++) {
            let char = text[right];
            windowCounts[char] = (windowCounts[char] || 0) + 1;
            
            if (mapP[char] && windowCounts[char] === mapP[char]) formed++;
            
            if (right - left + 1 > pattern.length) {
                char = text[left];
                if (mapP[char] && windowCounts[char] === mapP[char]) formed--;
                windowCounts[char]--;
                left++;
            }
            
            if (formed === required) count++;
        }
        
        console.log(count);
        rl.close();
    }
});
