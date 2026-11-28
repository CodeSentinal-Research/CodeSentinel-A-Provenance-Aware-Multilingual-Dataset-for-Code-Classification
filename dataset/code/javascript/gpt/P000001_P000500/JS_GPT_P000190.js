// P000190 - Find Duplicate in Array of N+1 Elements
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n + 1);
let slow = a[0], fast = a[0];
do {
    slow = a[slow];
    fast = a[a[fast]];
} while (slow !== fast);
fast = a[0];
while (slow !== fast) {
    slow = a[slow];
    fast = a[fast];
}
console.log(slow);
