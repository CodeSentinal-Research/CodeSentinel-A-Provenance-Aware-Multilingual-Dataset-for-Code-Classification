// Implement Queue Using Arrays
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let cap = parseInt(tokens[0], 10);
        let q = parseInt(tokens[1], 10);
        let idx = 2;
        let queue = [];
        for (const _ of Array.from({length: q}, (_, i) => i)) {
            let cmd = tokens[idx];
            if (cmd === "enqueue") {
                queue.push(parseInt(tokens[(idx + 1)], 10));
                idx += 2;
            } else {
                if (cmd === "dequeue") {
                    if (queue) {
                        console.log(queue.splice(0, 1)[0]);
                    }
                    idx += 1;
                } else {
                    if (cmd === "front") {
                        if (queue) {
                            console.log(queue[0]);
                        }
                        idx += 1;
                    } else {
                        if (cmd === "isEmpty") {
                            console.log(((queue.length !== undefined ? queue.length : queue.size) === 0 ? "true" : "false"));
                            idx += 1;
                        }
                    }
                }
            }
        }
    }
}
main();
