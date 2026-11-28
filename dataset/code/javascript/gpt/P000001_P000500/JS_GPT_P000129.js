// P000129 - Next Greater Element
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const ans = Array(n).fill(-1);
const stack = [];
for (let i = 0; i < n; i++) {
    while (stack.length && a[stack[stack.length - 1]] < a[i]) {
        ans[stack.pop()] = a[i];
    }
    stack.push(i);
}
console.log(ans.join(" "));
