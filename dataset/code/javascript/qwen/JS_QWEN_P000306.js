const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let stack = [], num = 0, lastNum = 0, sign = '+';
    for(let i=0; i<=s.length; i++) {
        let c = s[i];
        if(c >= '0' && c <= '9') num = num * 10 + parseInt(c);
        if((c < '0' || c > '9') && c !== ' ' || i === s.length) {
            if(sign === '+') { stack.push(num); lastNum = num; }
            else if(sign === '-') { stack.push(-num); lastNum = -num; }
            else if(sign === '*') { let prev = stack.pop(); stack.push(prev * num); }
            else if(sign === '/') { let prev = stack.pop(); stack.push(Math.trunc(prev / num)); }
            sign = c;
            num = 0;
        }
    }
    console.log(stack.reduce((a,b)=>a+b, 0));
    rl.close();
});
