const fs = require("fs");

const input = fs.readFileSync(0, "utf8").trim();
if (!input) process.exit(0);

const n = Number(input.split(/\s+/)[0]);
let result = 1n;

for (let i = 1; i <= n; i++) {
    result = result * BigInt(n + i) / BigInt(i);
}
result = result / BigInt(n + 1);

console.log(result.toString());
