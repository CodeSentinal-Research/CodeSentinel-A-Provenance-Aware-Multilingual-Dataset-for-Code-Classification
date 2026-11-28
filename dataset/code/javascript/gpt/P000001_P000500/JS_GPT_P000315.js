// Excel Sheet Column Number
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").trim();let n=0;for(const c of s)n=n*26+c.charCodeAt(0)-64;console.log(n);