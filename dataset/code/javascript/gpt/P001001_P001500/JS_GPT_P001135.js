// P001135 - Maximum Sum of Non-Adjacent Elements
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    if (n === 0) { console.log(0); return; }
    let inc = nums[0], exc = 0;
    for (let i = 1; i < n; i++) {
        const newInc = exc + nums[i];
        const newExc = Math.max(inc, exc);
        inc = newInc;
        exc = newExc;
    }
    console.log(Math.max(inc, exc));
}

main();
