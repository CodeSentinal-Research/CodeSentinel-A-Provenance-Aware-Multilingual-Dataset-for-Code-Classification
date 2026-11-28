const fs = require('fs');

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1 && input[0] !== '') {
        const n = parseInt(input[0], 10);
        const logs = input.slice(1);
        const res = new Array(n).fill(0);
        const stack = [];
        let prevTime = 0;
        for (const log of logs) {
            const [idStr, action, timeStr] = log.split(':');
            const fnId = parseInt(idStr, 10);
            const timestamp = parseInt(timeStr, 10);
            if (action === 'start') {
                if (stack.length > 0) {
                    res[stack[stack.length - 1]] += timestamp - prevTime;
                }
                stack.push(fnId);
                prevTime = timestamp;
            } else {
                res[stack.pop()] += timestamp - prevTime + 1;
                prevTime = timestamp + 1;
            }
        }
        console.log(res.join(' '));
    }
}

main();