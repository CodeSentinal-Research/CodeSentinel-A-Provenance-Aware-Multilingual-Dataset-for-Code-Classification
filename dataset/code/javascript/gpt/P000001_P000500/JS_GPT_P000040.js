const fs = require("fs");
fs.readFileSync(0, "utf8");
// P000040 - Print All ASCII Characters
for (let i = 32; i <= 126; i++) {
    console.log(`${i} ${String.fromCharCode(i)}`);
}
