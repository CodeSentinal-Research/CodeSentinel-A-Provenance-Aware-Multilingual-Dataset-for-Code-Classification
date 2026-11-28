// Word Ladder
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let begin_word = tokens[0];
        let end_word = tokens[1];
        let n = parseInt(tokens[2], 10);
        let word_list = new Set(tokens.slice(3, (3 + n)));
        if (!_in(end_word, word_list)) {
            console.log(0);
            return;
        }
        let q = deque([[begin_word, 1]]);
        let visited = new Set([begin_word]);
        while (q) {
            let [word, length] = q.popleft();
            if (word === end_word) {
                console.log(length);
                return;
            }
            for (const i of Array.from({length: (word.length !== undefined ? word.length : word.size)}, (_, i) => i)) {
                for (const c of "abcdefghijklmnopqrstuvwxyz") {
                    let nxt = ((word.slice(0, i) + c) + word.slice((i + 1)));
                    if ((_in(nxt, word_list) && !_in(nxt, visited))) {
                        visited.add(nxt);
                        q.push([nxt, (length + 1)]);
                    }
                }
            }
        }
        console.log(0);
    }
}
main();
