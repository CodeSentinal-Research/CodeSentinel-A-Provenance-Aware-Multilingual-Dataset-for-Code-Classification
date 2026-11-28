// Sort Characters of a String
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").replace(/\r?\n$/,"");
console.log([...s].sort((a,b)=>a.localeCompare(b)).join(""));