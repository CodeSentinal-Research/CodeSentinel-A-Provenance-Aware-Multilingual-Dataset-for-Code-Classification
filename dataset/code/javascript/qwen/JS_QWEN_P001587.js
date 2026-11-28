const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let count = 0;
    let lastIdx = [-1, -1, -1]; // a, e, i, o, u -> map to 0-4
    
    for (let i = 0; i < s.length; i++) {
        if (s[i] === 'a') lastIdx[0] = i;
        else if (s[i] === 'e') lastIdx[1] = i;
        else if (s[i] === 'i') lastIdx[2] = i;
        else if (s[i] === 'o') lastIdx[3] = i;
        else if (s[i] === 'u') lastIdx[4] = i;
        
        if (Math.min(...lastIdx) >= 0) {
            count += Math.min(...lastIdx) + 1;
        }
    }
    
    console.log(count);
    rl.close();
});
