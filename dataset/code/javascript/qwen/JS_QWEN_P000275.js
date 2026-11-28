const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let res = '', count = 1;
    for(let i=1; i<=s.length; i++) {
        if(s[i]===s[i-1]) count++;
        else { res += s[i-1]+count; count=1; }
    }
    console.log(res.length < s.length ? res : s);
    rl.close();
});
