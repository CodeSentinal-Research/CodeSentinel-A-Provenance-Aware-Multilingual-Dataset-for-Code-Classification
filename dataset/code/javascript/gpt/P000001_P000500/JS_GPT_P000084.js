const fs = require("fs");
const age = Number(fs.readFileSync(0, "utf8").trim());
// P000084 - Check Eligibility for Voting
console.log(age >= 18 ? "Eligible" : "Not Eligible");
