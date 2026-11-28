const fs = require('fs');

function calculate(s) {
    const stack = [];
    let num = 0;
    let sign = '+';
    for (let i = 0; i < s.length; i++) {
        const c = s[i];
        if (c >= '0' && c <= '9') {
            num = num * 10 + parseInt(c, 10);
        }
        if ((c !== ' ' && (c < '0' || c > '9')) || i === s.length - 1) {
            if (sign === '+') stack.push(num);
            else if (sign === '-') stack.push(-num);
            else if (sign === '*') stack.push(stack.pop() * num);
            else if (sign === '/') stack.push(Math.trunc(stack.pop() / num));
            sign = c;
            num = 0;
        }
    }
    return stack.reduce((a, b) => a + b, 0);
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim();
    if (input.length > 0) {
        console.log(calculate(input));
    }
}

main();