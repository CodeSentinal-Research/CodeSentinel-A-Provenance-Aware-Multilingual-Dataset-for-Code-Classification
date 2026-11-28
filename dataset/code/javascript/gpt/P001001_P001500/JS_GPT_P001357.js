// P001357 - Additive Number
const fs = require("fs");

function main() {
    const num = fs.readFileSync(0, "utf8").trim();
    if (!num) return;
    function isValid(n1, n2, start) {
        while (start < num.length) {
            const n3 = n1 + n2;
            const n3Str = n3.toString();
            if (!num.startsWith(n3Str, start)) return false;
            start += n3Str.length;
            n1 = n2;
            n2 = n3;
        }
        return true;
    }
    const n = num.length;
    for (let i = 1; i <= Math.floor(n / 2); i++) {
        if (num[0] === "0" && i > 1) break;
        const n1 = BigInt(num.slice(0, i));
        for (let j = 1; Math.max(i, j) <= n - i - j; j++) {
            if (num[i] === "0" && j > 1) break;
            const n2 = BigInt(num.slice(i, i + j));
            if (isValid(n1, n2, i + j)) {
                console.log("YES");
                return;
            }
        }
    }
    console.log("NO");
}

main();
