// Generate All Dice Roll Sequences
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function dice_rolls(target, cur) {
    if (target === 0) {
        console.log(...cur);
        return;
    }
    for (const i of Array.from({length: (7) - (1)}, (_, i) => (1) + i)) {
        if (i <= target) {
            dice_rolls((target - i), (cur + [i]));
        }
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let target = parseInt(tokens[0], 10);
        dice_rolls(target, []);
    }
}
main();
