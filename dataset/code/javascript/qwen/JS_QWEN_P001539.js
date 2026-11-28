const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let count = 0;
    let vowels = new Set(['a', 'e', 'i', 'o', 'u']);
    
    for (let i = 0; i < s.length; i++) {
        if (!vowels.has(s[i])) continue;
        let vowelSet = new Set();
        for (let j = i; j < s.length; j++) {
            if (vowels.has(s[j])) {
                vowelSet.add(s[j]);
                if (vowelSet.size === 5) count++;
            } else {
                break;
            }
        }
    }
    
    console.log(count);
    rl.close();
});
