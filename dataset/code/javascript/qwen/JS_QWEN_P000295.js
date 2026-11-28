const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let i=0, sign=1, res=0;
    while(i<s.length && s[i]===' ') i++;
    if(i<s.length && (s[i]==='+'||s[i]==='-')) { sign=s[i]==='-'?-1:1; i++; }
    while(i<s.length && /[0-9]/.test(s[i])) {
        res = res*10 + parseInt(s[i]);
        if(res*sign > 2**31-1) { console.log(2**31-1); rl.close(); return; }
        if(res*sign < -(2**31)) { console.log(-(2**31)); rl.close(); return; }
        i++;
    }
    console.log(res*sign);
    rl.close();
});
