const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let stack = [], sign = 1, num = 0, res = 0;
    for(let c of s) {
        if(c >= '0' && c <= '9') num = num * 10 + parseInt(c);
        else if(c === '+') { res += sign * num; num = 0; sign = 1; }
        else if(c === '-') { res += sign * num; num = 0; sign = -1; }
        else if(c === '(') { stack.push(res); stack.push(sign); res = 0; sign = 1; }
        else if(c === ')') { res += sign * num; num = 0; res *= stack.pop(); res += stack.pop(); }
    }
    console.log(res + sign * num);
    rl.close();
});
