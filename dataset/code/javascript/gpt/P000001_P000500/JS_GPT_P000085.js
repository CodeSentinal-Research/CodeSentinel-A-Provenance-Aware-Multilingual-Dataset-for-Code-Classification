const fs = require("fs");
const marks = Number(fs.readFileSync(0, "utf8").trim());
// P000085 - Grade Calculation
let grade;
if (marks >= 90) grade = "A";
else if (marks >= 80) grade = "B";
else if (marks >= 70) grade = "C";
else if (marks >= 60) grade = "D";
else grade = "F";
console.log(grade);
