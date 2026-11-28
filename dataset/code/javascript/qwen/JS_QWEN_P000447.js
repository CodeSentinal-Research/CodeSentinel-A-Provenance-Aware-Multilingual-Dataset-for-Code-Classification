const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let l=0, r=n, res=0;
    while(l<=r) {
        let m = Math.floor((l+r)/2);
        if(m*m <= n) { res=m; l=m+1; }
        else r=m-1;
    }
    console.log(res);
    rl.close();
});
