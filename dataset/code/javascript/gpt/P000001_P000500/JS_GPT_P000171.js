// P000171 - Segregate 0s and 1s
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const zeros = a.filter(x => x === 0);
const ones = a.filter(x => x === 1);
console.log(zeros.concat(ones).join(" "));
