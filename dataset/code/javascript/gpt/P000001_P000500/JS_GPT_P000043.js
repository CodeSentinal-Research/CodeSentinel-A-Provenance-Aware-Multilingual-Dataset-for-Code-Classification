const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000043 - Print Numbers from 1 to N
const arr = [];
for (let i = 1; i <= n; i++) arr.push(i);
console.log(arr.join(" "));
