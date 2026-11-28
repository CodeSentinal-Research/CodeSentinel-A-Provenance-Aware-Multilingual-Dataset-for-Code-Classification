// Capitalize First Letter of Each Word
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").replace(/\r?\n$/,"");
console.log(s.replace(/\S+/g,w=>w[0].toUpperCase()+w.slice(1)));