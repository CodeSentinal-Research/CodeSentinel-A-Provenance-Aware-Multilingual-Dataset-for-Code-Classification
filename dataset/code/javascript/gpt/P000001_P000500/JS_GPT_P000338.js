// Check if Two String Arrays are Equivalent
const fs=require("fs");
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const [a,b]=lines;
const s1=(a||"").trim().split(/\s+/).join("");
const s2=(b||"").trim().split(/\s+/).join("");
console.log(s1===s2?"Yes":"No");