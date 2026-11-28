const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const q = parseInt(tokens[0], 10);
        let idx = 1;
        const dq = [];
        for (let j = 0; j < q; j++) {
            const cmd = tokens[idx];
            if (cmd === 'insertFront') {
                dq.unshift(parseInt(tokens[idx+1], 10));
                idx += 2;
            } else if (cmd === 'insertLast') {
                dq.push(parseInt(tokens[idx+1], 10));
                idx += 2;
            } else if (cmd === 'deleteFront') {
                dq.shift();
                idx += 1;
            } else if (cmd === 'deleteLast') {
                dq.pop();
                idx += 1;
            } else if (cmd === 'getFront') {
                console.log(dq.length > 0 ? dq[0] : -1);
                idx += 1;
            } else if (cmd === 'getRear') {
                console.log(dq.length > 0 ? dq[dq.length - 1] : -1);
                idx += 1;
            } else if (cmd === 'isEmpty') {
                console.log(dq.length === 0 ? "true" : "false");
                idx += 1;
            } else if (cmd === 'size') {
                console.log(dq.length);
                idx += 1;
            }
        }
    }
}
main();