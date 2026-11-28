// P001260 - Construct String Without Three Consecutive Characters
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    let a = parseInt(input[0], 10);
    let b = parseInt(input[1], 10);
    let res = "";
    while (a > 0 || b > 0) {
        const len = res.length;
        if (len >= 2 && res[len - 1] === "a" && res[len - 2] === "a") {
            res += "b";
            b--;
        } else if (len >= 2 && res[len - 1] === "b" && res[len - 2] === "b") {
            res += "a";
            a--;
        } else if (a >= b) {
            res += "a";
            a--;
        } else {
            res += "b";
            b--;
        }
    }
    console.log(res);
}

main();
