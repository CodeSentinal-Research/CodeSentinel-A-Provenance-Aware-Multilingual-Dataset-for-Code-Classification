const fs = require("fs");
const s = fs.readFileSync(0, "utf8").trim();
// P000026 - Check Palindrome Number
if (s.startsWith("-")) {
    console.log("Not Palindrome");
} else {
    const rev = s.split("").reverse().join("");
    console.log(s === rev ? "Palindrome" : "Not Palindrome");
}
