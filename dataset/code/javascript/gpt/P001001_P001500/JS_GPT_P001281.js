// P001281 - Remove K Digits
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const num = input[0];
    let k = parseInt(input[1], 10);
    const stack = [];
    for (const c of num) {
        while (stack.length > 0 && k > 0 && stack[stack.length - 1] > c) {
            stack.pop();
            k--;
        }
        stack.push(c);
    }
    while (k > 0) {
        stack.pop();
        k--;
    }
    const res = stack.join("").replace(/^0+/, "");
    console.log(res ? res : "0");
}

main();
