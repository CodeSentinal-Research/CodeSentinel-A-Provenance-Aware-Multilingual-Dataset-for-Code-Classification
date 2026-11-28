const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [n, k] = input.split(/\s+/).map(Number);
    let res = [];
    function gen(curr, len) {
        if(len===k) { res.push(curr); return; }
        for(let i=0; i<n; i++) {
            gen(curr+String.fromCharCode(97+i), len+1);
        }
    }
    gen("", 0);
    console.log(res.join("\n"));
    rl.close();
});
