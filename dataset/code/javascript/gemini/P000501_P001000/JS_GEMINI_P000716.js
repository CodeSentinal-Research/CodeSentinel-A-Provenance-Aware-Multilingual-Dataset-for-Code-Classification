const fs = require('fs');
const pad = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];
function letterComb(digits, idx, cur) {
    if (idx === digits.length) {
        console.log(cur);
        return;
    }
    const d = parseInt(digits[idx], 10);
    for (const c of pad[d]) {
        letterComb(digits, idx + 1, cur + c);
    }
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        letterComb(tokens[0], 0, "");
    }
}
main();