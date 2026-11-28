// Search Product by Product Code
const fs=require("fs");
// Search Product by Product Code
// Input: N, then N lines "code|name|price|qty", then target code
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const targetCode=lines[n+1]||"";
let found=false;
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[0]===targetCode){console.log(lines[i]);found=true;break;}
}
if(!found)console.log("Product Not Found");