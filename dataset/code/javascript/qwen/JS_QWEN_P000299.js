const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let res = [];
    function gen(open, close, s) {
        if(s.length===2*n) { res.push(s); return; }
        if(open<n) gen(open+1, close, s+'(');
        if(close<open) gen(open, close+1, s+')');
    }
    gen(0,0,'');
    console.log(res.join(" "));
    rl.close();
});
