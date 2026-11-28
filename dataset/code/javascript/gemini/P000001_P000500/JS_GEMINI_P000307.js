const fs = require('fs');

function isValid(s) {
    let cnt = 0;
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(') cnt++;
        else if (s[i] === ')') {
            cnt--;
            if (cnt < 0) return false;
        }
    }
    return cnt === 0;
}

function removeInvalidParentheses(s) {
    let level = new Set([s]);
    while (level.size > 0) {
        const valid = [...level].filter(isValid);
        if (valid.length > 0) return valid;
        const nextLevel = new Set();
        for (const item of level) {
            for (let i = 0; i < item.length; i++) {
                if (item[i] === '(' || item[i] === ')') {
                    nextLevel.add(item.slice(0, i) + item.slice(i + 1));
                }
            }
        }
        level = nextLevel;
    }
    return [''];
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1 && input[0] !== '') {
        const res = removeInvalidParentheses(input[0]);
        res.forEach(str => console.log(str));
    }
}

main();