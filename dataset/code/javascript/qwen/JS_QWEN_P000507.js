const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let nodes = s.split(',');
    let stack = 1;
    for(let i=1; i<nodes.length; i++) {
        if(nodes[i]==='#') stack--;
        else stack++;
        if(stack<0) { console.log("false"); rl.close(); return; }
    }
    console.log(stack===0 ? "true" : "false");
    rl.close();
});
