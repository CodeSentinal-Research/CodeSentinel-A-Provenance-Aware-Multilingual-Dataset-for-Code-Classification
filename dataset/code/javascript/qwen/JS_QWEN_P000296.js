const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const num = parseInt(input.trim());
    const vals = [1000,900,500,400,100,90,50,40,10,9,5,4,1];
    const syms = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"];
    let res = '';
    let n = num;
    for(let i=0; i<vals.length; i++) {
        while(n>=vals[i]) { res+=syms[i]; n-=vals[i]; }
    }
    console.log(res);
    rl.close();
});
