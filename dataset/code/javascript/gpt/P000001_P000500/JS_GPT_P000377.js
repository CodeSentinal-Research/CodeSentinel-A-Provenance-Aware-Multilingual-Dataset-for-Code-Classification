// Search Vehicle by Registration Number
const fs=require("fs");
// Search Vehicle by Registration Number
// Input: N, then N lines "regNo|make|model|year", then target regNo
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const targetReg=lines[n+1]||"";
let found=false;
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[0]===targetReg){console.log(lines[i]);found=true;break;}
}
if(!found)console.log("Vehicle Not Found");