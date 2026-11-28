// Search Bank Account by Account Number
const fs=require("fs");
// Search Bank Account by Account Number
// Input: N, then N lines "accountNo|holder|type|balance", then target accountNo
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const targetAcc=lines[n+1]||"";
let found=false;
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[0]===targetAcc){console.log(lines[i]);found=true;break;}
}
if(!found)console.log("Account Not Found");