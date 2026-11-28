// Verify Preorder Serialization of a Binary Tree
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let s = _stdin_all.trim();
    if (s) {
        let slots = 1;
        for (const node of s.split(",")) {
            slots -= 1;
            if (slots < 0) {
                console.log("false");
                return;
            }
            if (node !== "#") {
                slots += 2;
            }
        }
        console.log((slots === 0 ? "true" : "false"));
    }
}
main();
