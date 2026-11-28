// Search Book by ISBN
const fs=require("fs");
// Search Book by ISBN
// Input: N, then N lines "isbn|title|author|year", then target isbn
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const targetIsbn=lines[n+1]||"";
let found=false;
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[0]===targetIsbn){console.log(lines[i]);found=true;break;}
}
if(!found)console.log("Book Not Found");