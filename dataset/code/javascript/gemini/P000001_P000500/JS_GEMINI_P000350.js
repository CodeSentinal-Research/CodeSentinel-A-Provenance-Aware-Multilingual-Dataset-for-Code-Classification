const fs = require('fs');

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        const s = input[0];
        const k = parseInt(input[1], 10);
        const stack = [];
        for (const c of s) {
            if (stack.length > 0 && stack[stack.length - 1][0] === c) {
                stack[stack.length - 1][1]++;
                if (stack[stack.length - 1][1] === k) stack.pop();
            } else {
                stack.push([c, 1]);
            }
        }
        console.log(stack.map(([c, count]) => c.repeat(count)).join(''));
    }
}

main();