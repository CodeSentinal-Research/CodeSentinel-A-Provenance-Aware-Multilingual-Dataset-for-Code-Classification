const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let n = s.length;
    let count = 0;
    for(let i=0; i<n; i++) {
        // Odd length
        let l=i, r=i;
        while(l>=0 && r<n && s[l]===s[r]) { count++; l--; r++; }
        // Even length
        l=i; r=i+1;
        while(l>=0 && r<n && s[l]===s[r]) { count++; l--; r++; }
    }
    console.log(count);
    rl.close();
});
