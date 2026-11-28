// P000222 - Minimum Number of Platforms Required
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const arr = tokens.slice(p, p + n).sort((x, y) => x - y); p += n;
const dep = tokens.slice(p, p + n).sort((x, y) => x - y);
let i = 0, j = 0, cur = 0, maxPlat = 0;
while (i < n && j < n) {
    if (arr[i] <= dep[j]) { cur++; maxPlat = Math.max(maxPlat, cur); i++; }
    else { cur--; j++; }
}
console.log(maxPlat);
