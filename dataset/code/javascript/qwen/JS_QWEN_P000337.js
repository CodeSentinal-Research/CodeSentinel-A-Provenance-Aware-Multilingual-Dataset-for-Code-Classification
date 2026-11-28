const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let maxScore = 0, zeros = 0, ones = 0;
    for(let c of s) if(c==='0') zeros++; else ones++;
    let leftZeros = 0, leftOnes = 0;
    for(let i=0; i<s.length-1; i++) {
        if(s[i]==='0') leftZeros++; else leftOnes++;
        let score = leftZeros + (ones - leftOnes);
        maxScore = Math.max(maxScore, score);
    }
    console.log(maxScore);
    rl.close();
});
