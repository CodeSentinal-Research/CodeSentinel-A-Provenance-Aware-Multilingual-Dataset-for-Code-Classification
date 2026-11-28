const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s1 = lines[0];
        const s2 = lines[1];
        
        if (s1.length > s2.length) { console.log("NO"); rl.close(); return; }
        
        let mapS1 = {};
        for (let c of s1) mapS1[c] = (mapS1[c] || 0) + 1;
        
        let windowCounts = {};
        let formed = 0;
        let required = Object.keys(mapS1).length;
        
        let left = 0;
        for (let right = 0; right < s2.length; right++) {
            let char = s2[right];
            windowCounts[char] = (windowCounts[char] || 0) + 1;
            
            if (mapS1[char] && windowCounts[char] === mapS1[char]) formed++;
            
            if (right - left + 1 > s1.length) {
                char = s2[left];
                if (mapS1[char] && windowCounts[char] === mapS1[char]) formed--;
                windowCounts[char]--;
                left++;
            }
            
            if (formed === required) { console.log("YES"); rl.close(); return; }
        }
        
        console.log("NO");
        rl.close();
    }
});
