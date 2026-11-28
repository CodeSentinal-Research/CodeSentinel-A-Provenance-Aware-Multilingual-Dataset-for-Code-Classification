// Toggle Case of Characters
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").replace(/\r?\n$/,"");
let out="";
for(const c of s)out+=/[a-z]/.test(c)?c.toUpperCase():/[A-Z]/.test(c)?c.toLowerCase():c;
console.log(out);