// Longest Common Prefix
const fs=require("fs");
const lines=fs.readFileSync(0,"utf8").split(/\r?\n/),n=Number(lines[0]);
let p=lines[1]||"";
for(const w of lines.slice(2,n+1)){let i=0;while(i<p.length&&i<w.length&&p[i]===w[i])i++;p=p.slice(0,i);}
console.log(p);