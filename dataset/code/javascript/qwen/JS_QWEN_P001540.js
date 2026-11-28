const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let count = 0;
    let vowels = new Set(['a', 'e', 'i', 'o', 'u']);
    
    let lastVowelIdx = -1;
    let vowelCounts = new Array(5).fill(0); // a, e, i, o, u
    
    // Simplified approach for brevity
    let map = {};
    let left = 0;
    let formed = 0;
    
    // This is complex for a single pass, using nested loop for correctness within constraints
    for (let i = 0; i < s.length; i++) {
        if (!vowels.has(s[i])) continue;
        let seen = new Set();
        for (let j = i; j < s.length; j++) {
            if (vowels.has(s[j])) {
                seen.add(s[j]);
                if (seen.size === 5) {
                    count += (s.length - j);
                    break;
                }
            } else {
                break;
            }
        }
    }
    
    console.log(count);
    rl.close();
});
