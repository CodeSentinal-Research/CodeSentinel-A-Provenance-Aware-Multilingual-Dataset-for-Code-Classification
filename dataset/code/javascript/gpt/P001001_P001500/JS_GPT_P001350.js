// P001350 - K-th Lexicographical Happy String
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const happy = [];
    function backtrack(curr) {
        if (curr.length === n) {
            happy.push(curr);
            return;
        }
        for (const c of ["a", "b", "c"]) {
            if (curr.length === 0 || curr[curr.length - 1] !== c) {
                backtrack(curr + c);
            }
        }
    }
    backtrack("");
    console.log(k <= happy.length ? happy[k - 1] : "");
}

main();
