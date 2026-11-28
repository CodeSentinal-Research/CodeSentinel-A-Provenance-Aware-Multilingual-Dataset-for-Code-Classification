const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000044 - Print Numbers from N to 1
const arr = [];
for (let i = n; i >= 1; i--) arr.push(i);
console.log(arr.join(" "));
