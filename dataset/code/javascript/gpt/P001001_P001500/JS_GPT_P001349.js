// P001349 - Restore Array from Pattern
const fs = require("fs");

function main() {
    const pattern = fs.readFileSync(0, "utf8").trim();
    if (!pattern) return;
    const stack = [];
    let res = "";
    for (let i = 0; i <= pattern.length; i++) {
        stack.push(i + 1);
        if (i === pattern.length || pattern[i] === "I") {
            while (stack.length > 0) res += stack.pop();
        }
    }
    console.log(res);
}

main();
