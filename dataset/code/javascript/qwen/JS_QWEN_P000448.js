const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let l=0, r=n, res=false;
    while(l<=r) {
        let m = Math.floor((l+r)/2);
        if(m*m === n) { res=true; break; }
        else if(m*m < n) l=m+1;
        else r=m-1;
    }
    console.log(res ? "Yes" : "No");
    rl.close();
});
