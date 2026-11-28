// Remove All Occurrences of a Character
const fs=require("fs");
const [s,c]=fs.readFileSync(0,"utf8").split(/\r?\n/);
console.log([...(s||"")].filter(x=>x!==(c||"")).join(""));