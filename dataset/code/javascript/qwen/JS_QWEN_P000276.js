const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let s = "1";
    for(let i=1; i<n; i++) {
        let next = '', count=1;
        for(let j=1; j<=s.length; j++) {
            if(s[j]===s[j-1]) count++;
            else { next += count+s[j-1]; count=1; }
        }
        s = next;
    }
    console.log(s);
    rl.close();
});
