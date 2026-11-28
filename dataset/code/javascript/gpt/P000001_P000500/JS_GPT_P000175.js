// P000175 - Wave Array
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n).sort((x, y) => x - y);
for (let i = 0; i < n - 1; i += 2) {
    [a[i], a[i + 1]] = [a[i + 1], a[i]];
}
console.log(a.join(" "));
