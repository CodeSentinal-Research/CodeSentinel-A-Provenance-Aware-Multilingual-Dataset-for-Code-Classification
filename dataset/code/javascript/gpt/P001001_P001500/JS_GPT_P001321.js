// P001321 - Letter Combinations of a Phone Number
const fs = require("fs");

function main() {
    const digits = fs.readFileSync(0, "utf8").trim();
    if (!digits) return;
    const map = {
        "2": "abc", "3": "def", "4": "ghi", "5": "jkl",
        "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"
    };
    const results = [];
    function backtrack(idx, path) {
        if (idx === digits.length) {
            results.push(path);
            return;
        }
        const letters = map[digits[idx]] || "";
        for (const c of letters) {
            backtrack(idx + 1, path + c);
        }
    }
    backtrack(0, "");
    console.log(results.join(" "));
}

main();
