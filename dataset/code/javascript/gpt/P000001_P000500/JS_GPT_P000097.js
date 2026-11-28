const fs = require("fs");
const s = fs.readFileSync(0, "utf8").trim();
// P000097 - Check Duck Number
const isDuck = !s.startsWith("0") && s.includes("0");
console.log(isDuck ? "Duck" : "Not Duck");
