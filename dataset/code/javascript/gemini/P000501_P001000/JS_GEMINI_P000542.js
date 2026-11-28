const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const q = parseInt(tokens[0], 10);
        let idx = 1;
        const queue = [];
        for (let i = 0; i < q; i++) {
            const cmd = tokens[idx];
            if (cmd === 'pushFront') {
                queue.unshift(parseInt(tokens[idx+1], 10));
                idx += 2;
            } else if (cmd === 'pushMiddle') {
                // Calculate midpoint to prevent potential overflow
                const mid = Math.floor(queue.length / 2);
                queue.splice(mid, 0, parseInt(tokens[idx+1], 10));
                idx += 2;
            } else if (cmd === 'pushBack') {
                queue.push(parseInt(tokens[idx+1], 10));
                idx += 2;
            } else if (cmd === 'popFront') {
                console.log(queue.length > 0 ? queue.shift() : -1);
                idx += 1;
            } else if (cmd === 'popMiddle') {
                if (queue.length === 0) console.log(-1);
                else {
                    // Calculate midpoint to prevent potential overflow
                    const mid = Math.floor((queue.length - 1) / 2);
                    console.log(queue.splice(mid, 1)[0]);
                }
                idx += 1;
            } else if (cmd === 'popBack') {
                console.log(queue.length > 0 ? queue.pop() : -1);
                idx += 1;
            }
        }
    }
}
main();