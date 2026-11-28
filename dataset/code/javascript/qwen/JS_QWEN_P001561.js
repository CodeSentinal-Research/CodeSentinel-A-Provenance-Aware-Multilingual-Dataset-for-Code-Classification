const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const s = lines[0];
        const m = parseInt(lines[1]);
        const words = lines[2].split(/\s+/);
        
        if (words.length === 0) { console.log(-1); rl.close(); return; }
        
        let wordLen = words[0].length;
        let totalLen = wordLen * words.length;
        let wordCount = {};
        for (let w of words) wordCount[w] = (wordCount[w] || 0) + 1;
        
        let res = [];
        
        for (let i = 0; i < wordLen; i++) {
            let left = i;
            let right = i;
            let currentCount = {};
            let formed = 0;
            
            while (right + wordLen <= s.length) {
                let word = s.substring(right, right + wordLen);
                right += wordLen;
                
                if (wordCount[word]) {
                    currentCount[word] = (currentCount[word] || 0) + 1;
                    if (currentCount[word] === wordCount[word]) formed++;
                    
                    while (currentCount[word] > wordCount[word]) {
                        let leftWord = s.substring(left, left + wordLen);
                        currentCount[leftWord]--;
                        if (currentCount[leftWord] < wordCount[leftWord]) formed--;
                        left += wordLen;
                    }
                    
                    if (formed === Object.keys(wordCount).length) res.push(left);
                } else {
                    currentCount = {};
                    formed = 0;
                    left = right;
                }
            }
        }
        
        console.log(res.length > 0 ? res.join(" ") : -1);
        rl.close();
    }
});
