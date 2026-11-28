// Count Subarrays with Equal Number of Vowels and Consonants
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function count_equal_vowels_consonants(s) {
    let vowels = new Set("aeiouAEIOU");
    let prefix = 0;
    let count = 0;
    let freq = defaultdict(Number);
    freq[0] = 1;
    for (const ch of s) {
        if (/^[a-zA-Z]+$/.test(ch)) {
            prefix += (_in(ch, vowels) ? 1 : -(1));
            count += freq[prefix];
            freq[prefix] += 1;
        }
    }
    return count;
}
let s = _stdin_next_line().trim();
console.log(count_equal_vowels_consonants(s));
