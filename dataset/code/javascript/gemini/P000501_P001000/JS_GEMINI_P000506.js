const fs = require('fs');
let idx = 0;
function parse(s) {
    const st = [];
    let num = 0, sign = '+';
    while (idx < s.length) {
        const c = s[idx++];
        if (!isNaN(c) && c !== ' ') num = num * 10 + Number(c);
        if (c === '(') num = parse(s);
        if (['+', '-', '*', '/', ')'].includes(c) || idx === s.length) {
            if (sign === '+') st.push(num);
            else if (sign === '-') st.push(-num);
            else if (sign === '*') st.push(st.pop() * num);
            else if (sign === '/') st.push(Math.trunc(st.pop() / num));
            if (c === ')') break;
            sign = c;
            num = 0;
        }
    }
    return st.reduce((a, b) => a + b, 0);
}
function main() {
    const s = fs.readFileSync(0, 'utf-8').trim();
    if (s) {
        idx = 0;
        console.log(parse(s));
    }
}
main();