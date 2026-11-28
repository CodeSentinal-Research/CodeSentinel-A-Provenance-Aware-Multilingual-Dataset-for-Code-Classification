// Search Student by Roll Number
const fs=require("fs");
// Search Student by Roll Number
// Input: N, then N lines "rollNo|name|grade|marks", then target rollNo
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const targetRoll=lines[n+1]||"";
let found=false;
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[0]===targetRoll){console.log(lines[i]);found=true;break;}
}
if(!found)console.log("Record Not Found");