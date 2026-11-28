const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    const map = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000};
    let res=0;
    for(let i=0; i<s.length; i++) {
        if(i+1<s.length && map[s[i]]<map[s[i+1]]) res-=map[s[i]];
        else res+=map[s[i]];
    }
    console.log(res);
    rl.close();
});
