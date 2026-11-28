const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const expr = input.trim();
    let res = [];
    function diffWays(s) {
        if (!isNaN(parseInt(s))) return [parseInt(s)];
        let results = [];
        for (let i = 0; i < s.length; i++) {
            if (['+','-','*'].includes(s[i])) {
                let left = diffWays(s.substring(0, i));
                let right = diffWays(s.substring(i+1));
                for (let l of left) {
                    for (let r of right) {
                        if (s[i]==='+') results.push(l+r);
                        else if (s[i]==='-') results.push(l-r);
                        else results.push(l*r);
                    }
                }
            }
        }
        return results;
    }
    console.log(diffWays(expr).sort((a,b)=>a-b).join(" "));
    rl.close();
});
