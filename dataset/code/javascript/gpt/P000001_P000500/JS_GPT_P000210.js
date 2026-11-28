// P000210 - Find Common Elements in Three Sorted Arrays
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const aN = tokens[p++], bN = tokens[p++], cN = tokens[p++];
const a = tokens.slice(p, p + aN); p += aN;
const b = tokens.slice(p, p + bN); p += bN;
const c = tokens.slice(p, p + cN);
let i = 0, j = 0, k = 0;
const out = [];
while (i < aN && j < bN && k < cN) {
    if (a[i] === b[j] && b[j] === c[k]) {
        out.push(a[i]);
        i++; j++; k++;
    } else {
        const minVal = Math.min(a[i], b[j], c[k]);
        if (a[i] === minVal) i++;
        else if (b[j] === minVal) j++;
        else k++;
    }
}
console.log(out.join(" "));
