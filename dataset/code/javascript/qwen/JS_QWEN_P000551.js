const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let q = ["1"];
    let res = [];
    for(let i=0; i<n; i++) {
        let curr = q.shift();
        res.push(curr);
        q.push(curr+"0");
        q.push(curr+"1");
    }
    console.log(res.join(" "));
    rl.close();
});
