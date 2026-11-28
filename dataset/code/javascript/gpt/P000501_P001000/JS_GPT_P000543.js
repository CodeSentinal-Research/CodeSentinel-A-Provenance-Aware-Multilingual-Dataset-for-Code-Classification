// Data Stream as Disjoint Intervals
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
        let nums = new Set();
        for (const _ of Array.from({length: q}, (_, i) => i)) {
            let cmd = tokens[idx];
            if (cmd === "addNum") {
                nums.add(parseInt(tokens[(idx + 1)], 10));
                idx += 2;
            } else {
                if (cmd === "getIntervals") {
                    let sorted_nums = [...nums].sort((a, b) => a < b ? -1 : a > b ? 1 : 0);
                    let intervals = [];
                    for (const x of sorted_nums) {
                        if ((intervals && (intervals[-(1)][1] + 1) === x)) {
                            intervals[-(1)][1] = x;
                        } else {
                            intervals.push([x, x]);
                        }
                    }
                    console.log([...intervals].map(([a, b]) => `[${a},${b}]`).join(" "));
                    idx += 1;
                }
            }
        }
    }
}
main();
