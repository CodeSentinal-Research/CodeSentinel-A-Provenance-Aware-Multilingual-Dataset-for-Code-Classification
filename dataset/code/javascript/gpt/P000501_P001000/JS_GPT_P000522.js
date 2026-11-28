// Design Browser History
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let home = tokens[0];
        let q = parseInt(tokens[1], 10);
        let idx = 2;
        let history = [home];
        let curr = 0;
        for (const _ of Array.from({length: q}, (_, i) => i)) {
            let cmd = tokens[idx];
            if (cmd === "visit") {
                let url = tokens[(idx + 1)];
                history = history.slice(0, (curr + 1));
                history.push(url);
                curr += 1;
                idx += 2;
            } else {
                if (cmd === "back") {
                    let steps = parseInt(tokens[(idx + 1)], 10);
                    curr = Math.max(0, (curr - steps));
                    console.log(history[curr]);
                    idx += 2;
                } else {
                    if (cmd === "forward") {
                        steps = parseInt(tokens[(idx + 1)], 10);
                        curr = Math.min(((history.length !== undefined ? history.length : history.size) - 1), (curr + steps));
                        console.log(history[curr]);
                        idx += 2;
                    }
                }
            }
        }
    }
}
main();
