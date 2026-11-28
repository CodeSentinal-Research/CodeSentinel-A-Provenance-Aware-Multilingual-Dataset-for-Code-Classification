// Search Employee by Employee ID
const fs=require("fs");
// Search Employee by Employee ID
// Input: N, then N lines "empId|name|dept|salary", then target empId
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const targetId=lines[n+1]||"";
let found=false;
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[0]===targetId){console.log(lines[i]);found=true;break;}
}
if(!found)console.log("Record Not Found");