const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let res = [];
    function genNum(curr, last, len) {
        if(len===n) { res.push(curr); return; }
        for(let i=last+1; i<=9; i++) {
            genNum(curr*10+i, i, len+1);
        }
    }
    for(let i=1; i<=9; i++) genNum(i, i, 1);
    console.log(res.join("\n"));
    rl.close();
});
