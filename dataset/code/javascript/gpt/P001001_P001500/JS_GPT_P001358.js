// P001358 - Generate Generalized Abbreviations
const fs = require("fs");

function main() {
    const word = fs.readFileSync(0, "utf8").trim();
    if (!word) return;
    const res = [];
    function backtrack(pos, cur, count) {
        if (pos === word.length) {
            res.push(cur + (count > 0 ? count : ""));
            return;
        }
        backtrack(pos + 1, cur, count + 1);
        backtrack(pos + 1, cur + (count > 0 ? count : "") + word[pos], 0);
    }
    backtrack(0, "", 0);
    res.sort();
    console.log(res.join(" "));
}

main();
