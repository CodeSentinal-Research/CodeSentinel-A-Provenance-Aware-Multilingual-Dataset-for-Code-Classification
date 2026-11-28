// P000131 - Leaders in an Array
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const leaders = [];
let rightMax = -Infinity;
for (let i = n - 1; i >= 0; i--) {
    if (a[i] >= rightMax) {
        leaders.push(a[i]);
        rightMax = a[i];
    }
}
leaders.reverse();
console.log(leaders.join(" "));
