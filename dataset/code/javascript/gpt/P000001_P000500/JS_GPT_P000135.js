// P000135 - Sort Colors (Dutch National Flag)
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
let lo = 0, mid = 0, hi = n - 1;
while (mid <= hi) {
    if (a[mid] === 0) {
        [a[lo], a[mid]] = [a[mid], a[lo]];
        lo++; mid++;
    } else if (a[mid] === 1) {
        mid++;
    } else {
        [a[mid], a[hi]] = [a[hi], a[mid]];
        hi--;
    }
}
console.log(a.join(" "));
