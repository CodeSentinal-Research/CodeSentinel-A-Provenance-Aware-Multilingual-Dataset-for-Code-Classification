// Queue Using Stacks
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
        let [s1, s2] = [[], []];
        for (const _ of Array.from({length: q}, (_, i) => i)) {
            let cmd = tokens[idx];
            if (cmd === "push") {
                s1.push(parseInt(tokens[(idx + 1)], 10));
                idx += 2;
            } else {
                if (cmd === "pop") {
                    if (!(s2)) {
                        while (s1) {
                            s2.push(s1.pop());
                        }
                    }
                    if (s2) {
                        console.log(s2.pop());
                    }
                    idx += 1;
                } else {
                    if (cmd === "peek") {
                        if (!(s2)) {
                            while (s1) {
                                s2.push(s1.pop());
                            }
                        }
                        if (s2) {
                            console.log(s2[-(1)]);
                        }
                        idx += 1;
                    } else {
                        if (cmd === "empty") {
                            console.log(((!(s1) && !(s2)) ? "true" : "false"));
                            idx += 1;
                        }
                    }
                }
            }
        }
    }
}
main();
