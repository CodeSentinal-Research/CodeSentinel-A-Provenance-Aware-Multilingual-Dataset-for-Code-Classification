// Matchsticks to Square
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function can_make_square(matchsticks) {
    let total = matchsticks.reduce((a, b) => a + b, 0);
    if (((total % 4) !== 0 || (matchsticks.length !== undefined ? matchsticks.length : matchsticks.size) < 4)) {
        return false;
    }
    let side = Math.floor(total / 4);
    matchsticks.sort();
    if (matchsticks[0] > side) {
        return false;
    }
    let sides = ([0] * 4);
    function backtrack(idx) {
        if (idx === (matchsticks.length !== undefined ? matchsticks.length : matchsticks.size)) {
            return sides[0] === sides[1] && sides[1] === sides[2] && sides[2] === sides[3] && sides[3] === side;
        }
        for (const i of Array.from({length: 4}, (_, i) => i)) {
            if ((sides[i] + matchsticks[idx]) <= side) {
                sides[i] += matchsticks[idx];
                if (backtrack((idx + 1))) {
                    return true;
                }
                sides[i] -= matchsticks[idx];
            }
            if (sides[i] === 0) {
                break;
            }
        }
        return false;
    }
    return backtrack(0);
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let matchsticks = Array.from(tokens.slice(1, (1 + n)).map(Number));
        console.log((can_make_square(matchsticks) ? "true" : "false"));
    }
}
main();
