const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000019 - Print Multiplication Table
for (let i = 1; i <= 10; i++) {
    console.log(`${n} x ${i} = ${n * i}`);
}
