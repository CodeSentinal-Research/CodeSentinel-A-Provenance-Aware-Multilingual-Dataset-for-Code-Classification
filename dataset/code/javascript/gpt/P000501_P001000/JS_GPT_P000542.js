// Design Front Middle Back Queue
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let q = parseInt(tokens[0], 10);
        let idx = 1;
        let queue = [];
        for (const _ of Array.from({length: q}, (_, i) => i)) {
            let cmd = tokens[idx];
            if (cmd === "pushFront") {
                queue.splice(0, 0, parseInt(tokens[(idx + 1)], 10));
                idx += 2;
            } else {
                if (cmd === "pushMiddle") {
                    let mid = Math.floor((queue.length !== undefined ? queue.length : queue.size) / 2);
                    queue.splice(mid, 0, parseInt(tokens[(idx + 1)], 10));
                    idx += 2;
                } else {
                    if (cmd === "pushBack") {
                        queue.push(parseInt(tokens[(idx + 1)], 10));
                        idx += 2;
                    } else {
                        if (cmd === "popFront") {
                            console.log((queue ? queue.splice(0, 1)[0] : -(1)));
                            idx += 1;
                        } else {
                            if (cmd === "popMiddle") {
                                if (!(queue)) {
                                    console.log(-(1));
                                } else {
                                    mid = Math.floor(((queue.length !== undefined ? queue.length : queue.size) - 1) / 2);
                                    console.log(queue.splice(mid, 1)[0]);
                                }
                                idx += 1;
                            } else {
                                if (cmd === "popBack") {
                                    console.log((queue ? queue.pop() : -(1)));
                                    idx += 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
main();
