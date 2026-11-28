// Remove All Consonants
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").replace(/\r?\n$/,"");
console.log(s.replace(/[b-df-hj-np-tv-z]/gi,""));