// P001370 - Maximum Number by Swapping Digits
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const numStr = input[0];
    const k = parseInt(input[1], 10);
    const digits = numStr.split("");
    let maxNum = numStr;
    function backtrack(idx, swapsLeft) {
        const curStr = digits.join("");
        if (curStr > maxNum) maxNum = curStr;
        if (swapsLeft === 0 || idx >= digits.length) return;
        let maxD = digits[idx];
        for (let i = idx + 1; i < digits.length; i++) {
            if (digits[i] > maxD) maxD = digits[i];
        }
        if (maxD !== digits[idx]) swapsLeft--;
        for (let i = digits.length - 1; i >= idx; i--) {
            if (digits[i] === maxD) {
                const temp = digits[idx]; digits[idx] = digits[i]; digits[i] = temp;
                backtrack(idx + 1, swapsLeft);
                digits[i] = digits[idx]; digits[idx] = temp;
            }
        }
    }
    backtrack(0, k);
    console.log(maxNum);
}

main();
