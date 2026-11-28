// Add Two Numbers Represented by Linked Lists
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let lines = _stdin_all.trim().split("\n");
    if (lines) {
        let t1 = Array.from(lines[0].trim().split(/\s+/).map(Number));
        let t2 = ((lines.length !== undefined ? lines.length : lines.size) > 1 ? Array.from(lines[1].trim().split(/\s+/).map(Number)) : []);
        let l1 = (((t1.length !== undefined ? t1.length : t1.size) > 0 && ((t1.length !== undefined ? t1.length : t1.size) - 1) === t1[0]) ? t1.slice(1) : t1);
        let l2 = (((t2.length !== undefined ? t2.length : t2.size) > 0 && ((t2.length !== undefined ? t2.length : t2.size) - 1) === t2[0]) ? t2.slice(1) : t2);
        let carry = 0;
        let res = [];
        let [i, j] = [0, 0];
        while ((i < (l1.length !== undefined ? l1.length : l1.size) || j < (l2.length !== undefined ? l2.length : l2.size) || carry)) {
            let v1 = (i < (l1.length !== undefined ? l1.length : l1.size) ? l1[i] : 0);
            let v2 = (j < (l2.length !== undefined ? l2.length : l2.size) ? l2[j] : 0);
            let s = ((v1 + v2) + carry);
            res.push((s % 10));
            carry = Math.floor(s / 10);
            i += 1;
            j += 1;
        }
        console.log(...res);
    }
}
main();
