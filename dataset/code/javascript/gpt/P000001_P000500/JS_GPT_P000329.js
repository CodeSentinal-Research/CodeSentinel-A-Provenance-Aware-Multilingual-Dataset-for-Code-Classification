// Find the Difference
const fs=require("fs");
const [s,t]=fs.readFileSync(0,"utf8").split(/\r?\n/);let x=0;for(const c of s)x^=c.charCodeAt(0);for(const c of t)x^=c.charCodeAt(0);console.log(String.fromCharCode(x));