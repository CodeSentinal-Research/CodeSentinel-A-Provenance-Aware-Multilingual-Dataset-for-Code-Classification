const fs = require("fs");
const c = fs.readFileSync(0, "utf8").trim()[0];
// P000039 - Find ASCII Value
console.log(c.charCodeAt(0));
