const fs = require('fs');
function calculate(s) {
    const st = [];
    let res = 0, num = 0, sign = 1;
    for (const c of s) {
        if (!isNaN(c) && c !== ' ') {
            num = num * 10 + Number(c);
        } else if (c === '+' || c === '-') {
            res += sign * num;
            num = 0;
            sign = (c === '+') ? 1 : -1;
        } else if (c === '(') {
            st.push(res);
            st.push(sign);
            res = 0;
            sign = 1;
        } else if (c === ')') {
            res += sign * num;
            num = 0;
            res *= st.pop();
            res += st.pop();
        }
    }
    res += sign * num;
    return res;
}
function main() {
    const s = fs.readFileSync(0, 'utf-8').trim();
    if (s) console.log(calculate(s));
}
main();