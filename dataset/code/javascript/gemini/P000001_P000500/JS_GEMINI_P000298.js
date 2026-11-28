const fs = require('fs');

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1 && input[0] !== '') {
        const s = input[0];
        const stack = [-1];
        let maxLen = 0;
        for (let i = 0; i < s.length; i++) {
            if (s[i] === '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.length === 0) {
                    stack.push(i);
                } else {
                    maxLen = Math.max(maxLen, i - stack[stack.length - 1]);
                }
            }
        }
        console.log(maxLen);
    }
}

main();