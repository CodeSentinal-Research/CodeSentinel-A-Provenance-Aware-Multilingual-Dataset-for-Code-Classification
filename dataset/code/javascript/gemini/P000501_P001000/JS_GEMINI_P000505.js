const fs = require('fs');
function calculate(s) {
    const st = [];
    let num = 0, sign = '+';
    for (let i = 0; i < s.length; i++) {
        const c = s[i];
        if (!isNaN(c) && c !== ' ') num = num * 10 + Number(c);
        if ((isNaN(c) && c !== ' ') || i === s.length - 1) {
            if (sign === '+') st.push(num);
            else if (sign === '-') st.push(-num);
            else if (sign === '*') st.push(st.pop() * num);
            else if (sign === '/') st.push(Math.trunc(st.pop() / num));
            sign = c;
            num = 0;
        }
    }
    return st.reduce((a, b) => a + b, 0);
}
function main() {
    const s = fs.readFileSync(0, 'utf-8').trim();
    if (s) console.log(calculate(s));
}
main();