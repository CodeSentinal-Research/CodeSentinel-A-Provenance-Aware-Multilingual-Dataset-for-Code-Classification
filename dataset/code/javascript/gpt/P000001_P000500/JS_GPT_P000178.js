// P000178 - Sort Array According to Frequency
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const count = new Map();
for (const x of a) count.set(x, (count.get(x) || 0) + 1);
a.sort((x, y) => {
    const fx = count.get(x), fy = count.get(y);
    return fx !== fy ? fy - fx : x - y;
});
console.log(a.join(" "));
