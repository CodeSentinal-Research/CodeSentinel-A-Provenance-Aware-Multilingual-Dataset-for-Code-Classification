const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    if(n===0) console.log(0);
    else if(n<=2) console.log(1);
    else {
        let a=0, b=1, c=1;
        for(let i=3; i<=n; i++) {
            let next = a+b+c;
            a=b; b=c; c=next;
        }
        console.log(c);
    }
    rl.close();
});
