// Restore IP Addresses
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function restore_ip(s, idx, parts) {
    if ((parts.length !== undefined ? parts.length : parts.size) === 4) {
        if (idx === (s.length !== undefined ? s.length : s.size)) {
            console.log(parts.join("."));
        }
        return;
    }
    for (const l of Array.from({length: (4) - (1)}, (_, i) => (1) + i)) {
        if ((idx + l) <= (s.length !== undefined ? s.length : s.size)) {
            let part = s.slice(idx, (idx + l));
            if (((part[0] === "0" && (part.length !== undefined ? part.length : part.size) > 1) || parseInt(part, 10) > 255)) {
                continue;
            }
            restore_ip(s, (idx + l), (parts + [part]));
        }
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        restore_ip(tokens[0], 0, []);
    }
}
main();
