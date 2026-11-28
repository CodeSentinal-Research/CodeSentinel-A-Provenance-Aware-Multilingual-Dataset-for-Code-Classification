const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let res = "";
    for(let i=0; i<s.length; i++) {
        if(s[i]>='0' && s[i]<='9') res += String.fromCharCode(s[i-1].charCodeAt(0) + parseInt(s[i]));
        else res += s[i];
    }
    console.log(res);
    rl.close();
});
