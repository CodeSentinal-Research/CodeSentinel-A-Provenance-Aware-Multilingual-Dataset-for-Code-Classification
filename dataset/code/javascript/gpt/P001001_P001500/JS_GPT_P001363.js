// P001363 - Generate Binary Strings Without Consecutive Ones
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const n = parseInt(input, 10);
    const res = [];
    function backtrack(path) {
        if (path.length === n) {
            res.push(path);
            return;
        }
        backtrack(path + "0");
        if (path.length === 0 || path[path.length - 1] !== "1") {
            backtrack(path + "1");
        }
    }
    backtrack("");
    for (const s of res) console.log(s);
}

main();
