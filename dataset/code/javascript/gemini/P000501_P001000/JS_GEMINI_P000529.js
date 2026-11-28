const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const cap = parseInt(tokens[0], 10), q = parseInt(tokens[1], 10);
        let idx = 2;
        const queue = [];
        for (let i = 0; i < q; i++) {
            const cmd = tokens[idx];
            if (cmd === 'enqueue') {
                queue.push(parseInt(tokens[idx+1], 10));
                idx += 2;
            } else if (cmd === 'dequeue') {
                if (queue.length > 0) console.log(queue.shift());
                idx += 1;
            } else if (cmd === 'front') {
                if (queue.length > 0) console.log(queue[0]);
                idx += 1;
            } else if (cmd === 'isEmpty') {
                console.log(queue.length === 0 ? "true" : "false");
                idx += 1;
            }
        }
    }
}
main();