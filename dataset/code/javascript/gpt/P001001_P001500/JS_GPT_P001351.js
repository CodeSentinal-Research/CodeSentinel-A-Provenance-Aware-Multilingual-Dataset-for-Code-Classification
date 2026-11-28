// P001351 - Combination Iterator
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const chars = input[0];
    const len = parseInt(input[1], 10);
    const results = [];
    function backtrack(start, path) {
        if (path.length === len) {
            results.push(path);
            return;
        }
        for (let i = start; i < chars.length; i++) {
            backtrack(i + 1, path + chars[i]);
        }
    }
    backtrack(0, "");
    for (const s of results) console.log(s);
}

main();
