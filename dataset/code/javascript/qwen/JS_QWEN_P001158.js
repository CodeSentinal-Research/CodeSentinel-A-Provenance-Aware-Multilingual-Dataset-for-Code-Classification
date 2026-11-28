const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    if(n<=3) console.log(n);
    else {
        let res = 1;
        while(n>4) { res*=3; n-=3; }
        console.log(res*n);
    }
    rl.close();
});
