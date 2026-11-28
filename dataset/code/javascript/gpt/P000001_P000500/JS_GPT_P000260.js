// Convert to Lowercase
const fs=require("fs");
console.log(fs.readFileSync(0,"utf8").replace(/\r?\n$/,"").toLowerCase());