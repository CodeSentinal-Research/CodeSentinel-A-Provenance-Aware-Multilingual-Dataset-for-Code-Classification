const fs = require('fs');

function calculate(s) {
    const stack = [];
    let res = 0, num = 0, sign = 1;
    for (let i = 0; i < s.length; i++) {
        const c = s[i];
        if (c >= '0' && c <= '9') {
            num = num * 10 + parseInt(c, 10);
        } else if (c === '+' || c === '-') {
            res += sign * num;
            num = 0;
            sign = (c === '+') ? 1 : -1;
        } else if (c === '(') {
            stack.push(res);
            stack.push(sign);
            res = 0;
            sign = 1;
        } else if (c === ')') {
            res += sign * num;
            num = 0;
            const prevSign = stack.pop();
            const prevRes = stack.pop();
            res = prevRes + prevSign * res;
        }
    }
    res += sign * num;
    return res;
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim();
    if (input.length > 0) {
        console.log(calculate(input));
    }
}

main();