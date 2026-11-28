const fs = require("fs");
const c = fs.readFileSync(0, "utf8").trim()[0].toLowerCase();
// P000042 - Check Vowel or Consonant
console.log("aeiou".includes(c) ? "Vowel" : "Consonant");
