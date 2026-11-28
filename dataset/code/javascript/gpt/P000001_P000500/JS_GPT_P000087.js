const fs = require("fs");
const n = BigInt(fs.readFileSync(0, "utf8").trim());
// P000087 - Find Sum of Natural Numbers Using Formula
console.log(String(n * (n + 1n) / 2n));
