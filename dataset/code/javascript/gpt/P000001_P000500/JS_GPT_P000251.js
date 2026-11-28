// Reverse a String
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").replace(/\r?\n$/,"");
console.log([...s].reverse().join(""));