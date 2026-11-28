// Flatten Nested List Iterator
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let content = _stdin_all;
    if (content) {
        let tokens = content.trim().split(/\s+/);
        let ints = [...re.findall("-?\\d+", content)].map(x => parseInt(x, 10));
        let idx = 0;
        for (const token of tokens) {
            if (token === "next()") {
                if (idx < (ints.length !== undefined ? ints.length : ints.size)) {
                    console.log(ints[idx]);
                    idx += 1;
                }
            } else {
                if (token === "hasNext()") {
                    console.log((idx < (ints.length !== undefined ? ints.length : ints.size) ? "true" : "false"));
                }
            }
        }
    }
}
main();
