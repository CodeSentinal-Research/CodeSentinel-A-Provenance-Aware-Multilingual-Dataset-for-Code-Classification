const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const cap = parseInt(tokens[0], 10), q = parseInt(tokens[1], 10);
        let idx = 2;
        const queue = [];
        for (let i = 0; i < q; i++) {
            const cmd = tokens[idx];
            if (cmd === 'enQueue') {
                const x = parseInt(tokens[idx+1], 10);
                if (queue.length < cap) {
                    queue.push(x);
                    console.log("true");
                } else {
                    console.log("false");
                }
                idx += 2;
            } else if (cmd === 'deQueue') {
                if (queue.length > 0) {
                    queue.shift();
                    console.log("true");
                } else {
                    console.log("false");
                }
                idx += 1;
            } else if (cmd === 'Front') {
                console.log(queue.length > 0 ? queue[0] : -1);
                idx += 1;
            } else if (cmd === 'Rear') {
                console.log(queue.length > 0 ? queue[queue.length - 1] : -1);
                idx += 1;
            } else if (cmd === 'isEmpty') {
                console.log(queue.length === 0 ? "true" : "false");
                idx += 1;
            } else if (cmd === 'isFull') {
                console.log(queue.length === cap ? "true" : "false");
                idx += 1;
            }
        }
    }
}
main();