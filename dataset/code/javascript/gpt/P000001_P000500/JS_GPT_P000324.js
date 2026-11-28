// Repeated Substring Pattern
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").trim();console.log(s.length>1&&(s+s).slice(1,-1).includes(s)?"Yes":"No");