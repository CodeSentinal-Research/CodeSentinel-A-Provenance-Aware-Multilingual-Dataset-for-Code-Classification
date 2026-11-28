const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let res = [];
    function lexOrder(curr) {
        if(curr>n) return;
        res.push(curr);
        for(let i=0; i<=9; i++) {
            let next = curr*10+i;
            if(next>n) break;
            lexOrder(next);
        }
    }
    for(let i=1; i<=9; i++) lexOrder(i);
    console.log(res.join("\n"));
    rl.close();
});
