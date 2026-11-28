const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let stack = [];
    let i=0;
    while(i<s.length) {
        if(s[i]>='A' && s[i]<='Z') {
            let elem = s[i++];
            while(i<s.length && s[i]>='a' && s[i]<='z') elem+=s[i++];
            let num = '';
            while(i<s.length && s[i]>='0' && s[i]<='9') num+=s[i++];
            stack.push([elem, parseInt(num)||1]);
        } else if(s[i]==='(') {
            i++;
        } else if(s[i]===')') {
            i++;
            let num = '';
            while(i<s.length && s[i]>='0' && s[i]<='9') num+=s[i++];
            let mult = parseInt(num)||1;
            let temp = {};
            while(stack.length && typeof stack[stack.length-1][0] === 'string') {
                let [e, c] = stack.pop();
                temp[e] = (temp[e]||0) + c * mult;
            }
            for(let e in temp) stack.push([e, temp[e]]);
        }
    }
    let res = {};
    for(let [e, c] of stack) res[e] = (res[e]||0) + c;
    let keys = Object.keys(res).sort();
    let out = '';
    for(let k of keys) out += k + (res[k]>1?res[k]:'');
    console.log(out);
    rl.close();
});
