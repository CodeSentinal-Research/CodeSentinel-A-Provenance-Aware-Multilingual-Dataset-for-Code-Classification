const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0];
        const k = parseInt(lines[1]);
        
        let maxVowels = 0;
        let currVowels = 0;
        let vowels = new Set(['a', 'e', 'i', 'o', 'u']);
        
        for (let i = 0; i < k; i++) {
            if (vowels.has(s[i])) currVowels++;
        }
        
        maxVowels = currVowels;
        
        for (let i = k; i < s.length; i++) {
            if (vowels.has(s[i])) currVowels++;
            if (vowels.has(s[i - k])) currVowels--;
            maxVowels = Math.max(maxVowels, currVowels);
        }
        
        console.log(maxVowels);
        rl.close();
    }
});
