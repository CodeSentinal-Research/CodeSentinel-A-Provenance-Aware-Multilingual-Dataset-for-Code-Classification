const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000008 - Check Positive Negative or Zero
if (n > 0) {
    console.log("Positive");
} else if (n < 0) {
    console.log("Negative");
} else {
    console.log("Zero");
}
