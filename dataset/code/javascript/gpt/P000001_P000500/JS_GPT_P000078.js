const fs = require("fs");
let days = Number(fs.readFileSync(0, "utf8").trim());
// P000078 - Convert Days to Years Weeks Days
const years = Math.trunc(days / 365);
days = days % 365;
const weeks = Math.trunc(days / 7);
const remDays = days % 7;
console.log(years, weeks, remDays);
