const fs = require("fs");
const s = fs.readFileSync(0, "utf8").trim();
let sum = 0;
const out = [];
for (const ch of s) {
    sum += ch.charCodeAt(0) - 96;
    out.push(sum);
}
console.log(out.join(" "));
