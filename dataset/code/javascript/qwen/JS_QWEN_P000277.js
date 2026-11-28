const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let set = new Set(), l=0, maxL=0;
    for(let r=0; r<s.length; r++) {
        while(set.has(s[r])) set.delete(s[l++]);
        set.add(s[r]);
        maxL = Math.max(maxL, r-l+1);
    }
    console.log(maxL);
    rl.close();
});
