// Exclusive Time of Functions
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let m = parseInt(tokens[1], 10);
        let logs = tokens.slice(2, (2 + m));
        let res = ([0] * n);
        let stack = [];
        let prev_time = 0;
        for (const log of logs) {
            let [fid, typ, time] = log.split(":");
            [fid, time] = [parseInt(fid, 10), parseInt(time, 10)];
            if (typ === "start") {
                if (stack) {
                    res[stack[-(1)]] += (time - prev_time);
                }
                stack.push(fid);
                prev_time = time;
            } else {
                res[stack.pop()] += ((time - prev_time) + 1);
                prev_time = (time + 1);
            }
        }
        console.log(...res);
    }
}
main();
