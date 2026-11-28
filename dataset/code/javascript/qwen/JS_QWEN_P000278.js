const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let start=0, maxL=0;
    for(let i=0; i<s.length; i++) {
        for(let j=0; j<=1; j++) {
            let l=i, r=i+j;
            while(l>=0 && r<s.length && s[l]===s[r]) {
                if(r-l+1 > maxL) { start=l; maxL=r-l+1; }
                l--; r++;
            }
        }
    }
    console.log(s.substring(start, start+maxL));
    rl.close();
});
