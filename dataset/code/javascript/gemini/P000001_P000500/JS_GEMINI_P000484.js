const fs = require('fs');
function decodeString(s) {
    const numSt = [];
    const strSt = [];
    let currStr = '', currNum = 0;
    for (const c of s) {
        if (!isNaN(c) && c !== ' ') {
            currNum = currNum * 10 + Number(c);
        } else if (c === '[') {
            numSt.push(currNum);
            strSt.push(currStr);
            currStr = '';
            currNum = 0;
        } else if (c === ']') {
            const num = numSt.pop();
            const prev = strSt.pop();
            currStr = prev + currStr.repeat(num);
        } else {
            currStr += c;
        }
    }
    return currStr;
}
function main() {
    const s = fs.readFileSync(0, 'utf-8').trim();
    if (s) console.log(decodeString(s));
}
main();