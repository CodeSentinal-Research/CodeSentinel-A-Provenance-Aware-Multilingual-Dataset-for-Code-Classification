const fs = require("fs");
let [a, b] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000006 - Swap Two Numbers
[a, b] = [b, a];
console.log(a, b);
