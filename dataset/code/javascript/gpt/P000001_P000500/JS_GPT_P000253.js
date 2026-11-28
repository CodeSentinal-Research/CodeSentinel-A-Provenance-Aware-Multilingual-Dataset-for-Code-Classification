// Count Vowels in a String
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").replace(/\r?\n$/,"").toLowerCase();
let n=0;
for(const ch of s) if("aeiou".includes(ch)) n++;
console.log(n);