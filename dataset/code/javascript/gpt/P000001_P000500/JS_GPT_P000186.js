// P000186 - Maximum Length of Subarray with Positive Product
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
let pos = 0, neg = 0, maxLen = 0;
for (const x of a) {
    if (x === 0) {
        pos = 0; neg = 0;
    } else if (x > 0) {
        pos++;
        neg = neg > 0 ? neg + 1 : 0;
    } else {
        const temp = pos;
        pos = neg > 0 ? neg + 1 : 0;
        neg = temp + 1;
    }
    maxLen = Math.max(maxLen, pos);
}
console.log(maxLen);
