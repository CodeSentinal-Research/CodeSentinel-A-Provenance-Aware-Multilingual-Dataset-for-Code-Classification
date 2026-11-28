// P001354 - Split String into Fibonacci Sequence
const fs = require("fs");

function main() {
    const num = fs.readFileSync(0, "utf8").trim();
    if (!num) return;
    const MAX = 2147483647;
    const res = [];
    function backtrack(idx) {
        if (idx === num.length && res.length >= 3) return true;
        for (let i = idx + 1; i <= num.length; i++) {
            if (num[idx] === "0" && i > idx + 1) break;
            const val = parseInt(num.substring(idx, i), 10);
            if (val > MAX) break;
            const len = res.length;
            if (len >= 2 && val > res[len - 1] + res[len - 2]) break;
            if (len < 2 || val === res[len - 1] + res[len - 2]) {
                res.push(val);
                if (backtrack(i)) return true;
                res.pop();
            }
        }
        return false;
    }
    if (backtrack(0)) {
        console.log(res.join(" "));
    } else {
        console.log("");
    }
}

main();
