// P001251 - Maximum Units on a Truck
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const digits = input.split("").map(Number);
    let marker = digits.length;
    for (let i = digits.length - 1; i > 0; i--) {
        if (digits[i - 1] > digits[i]) {
            marker = i;
            digits[i - 1]--;
        }
    }
    for (let i = marker; i < digits.length; i++) digits[i] = 9;
    console.log(parseInt(digits.join(""), 10));
}

main();
