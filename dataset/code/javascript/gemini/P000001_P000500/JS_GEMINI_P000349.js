const fs = require('fs');

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1 && input[0] !== '') {
        const stack = [];
        for (const c of input[0]) {
            if (stack.length > 0 && stack[stack.length - 1] === c) {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        console.log(stack.join(''));
    }
}

main();