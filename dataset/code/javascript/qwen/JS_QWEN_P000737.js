const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    function diffWays(s) {
        if(!isNaN(parseInt(s))) return [parseInt(s)];
        let res = [];
        for(let i=0; i<s.length; i++) {
            if(['+','-','*'].includes(s[i])) {
                let left = diffWays(s.substring(0, i));
                let right = diffWays(s.substring(i+1));
                for(let l of left) {
                    for(let r of right) {
                        if(s[i]==='+') res.push(l+r);
                        else if(s[i]==='-') res.push(l-r);
                        else res.push(l*r);
                    }
                }
            }
        }
        return res;
    }
    console.log(diffWays(s).sort((a,b)=>a-b).join(" "));
    rl.close();
});
