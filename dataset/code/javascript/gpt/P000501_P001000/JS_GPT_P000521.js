// Increasing Order Removal
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let passes = 0;
        while (nums) {
            passes += 1;
            let rem = [];
            let last = -(parseFloat("inf"));
            for (const x of nums) {
                if (x > last) {
                    last = x;
                } else {
                    rem.push(x);
                }
            }
            nums = rem;
        }
        console.log(passes);
    }
}
main();
