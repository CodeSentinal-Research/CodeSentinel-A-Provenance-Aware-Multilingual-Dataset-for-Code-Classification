// P001254 - Largest Number Formation
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const digits = input.split("").map(Number);
    const last = new Array(10).fill(-1);
    for (let i = 0; i < digits.length; i++) last[digits[i]] = i;
    for (let i = 0; i < digits.length; i++) {
        let swapped = false;
        for (let d = 9; d > digits[i]; d--) {
            if (last[d] > i) {
                const temp = digits[i];
                digits[i] = digits[last[d]];
                digits[last[d]] = temp;
                swapped = true;
                break;
            }
        }
        if (swapped) break;
    }
    console.log(digits.join(""));
}

main();
