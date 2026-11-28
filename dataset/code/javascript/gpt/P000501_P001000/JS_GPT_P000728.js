// Remove Invalid Parentheses
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function is_valid(s) {
    let cnt = 0;
    for (const c of s) {
        if (c === "(") {
            cnt += 1;
        } else {
            if (c === ")") {
                cnt -= 1;
                if (cnt < 0) {
                    return false;
                }
            }
        }
    }
    return cnt === 0;
}
function remove_invalid_parentheses(s) {
    let level = new Set([s]);
    while (level) {
        let valid = [...[...level].filter(x => is_valid(x)).map(x => x)].sort((a, b) => a < b ? -1 : a > b ? 1 : 0);
        if (valid) {
            return valid;
        }
        let next_level = new Set();
        for (const item of level) {
            for (const i of Array.from({length: (item.length !== undefined ? item.length : item.size)}, (_, i) => i)) {
                if (_in(item[i], "()")) {
                    next_level.add((item.slice(0, i) + item.slice((i + 1))));
                }
            }
        }
        level = next_level;
    }
    return [""];
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        for (const ans of remove_invalid_parentheses(tokens[0])) {
            console.log(ans);
        }
    }
}
main();
