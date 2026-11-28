const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', () => {
    let res = [];
    for(let i=90; i>=65; i--) res.push(String.fromCharCode(i));
    console.log(res.join(" "));
    rl.close();
});
