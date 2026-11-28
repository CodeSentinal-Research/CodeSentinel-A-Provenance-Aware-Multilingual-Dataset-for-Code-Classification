function decodeString(s) {
    const strStack = [];
    const numStack = [];
    let curStr = "";
    let curNum = 0;

    for (const c of s) {
        if (/\d/.test(c)) {
            curNum = curNum * 10 + Number(c);
        } else if (c === '[') {
            numStack.push(curNum);
            strStack.push(curStr);
            curStr = "";
            curNum = 0;
        } else if (c === ']') {
            const k = numStack.pop();
            const prevStr = strStack.pop();
            curStr = prevStr + curStr.repeat(k);
        } else {
            curStr += c;
        }
    }
    return curStr;
}

module.exports = { decodeString };