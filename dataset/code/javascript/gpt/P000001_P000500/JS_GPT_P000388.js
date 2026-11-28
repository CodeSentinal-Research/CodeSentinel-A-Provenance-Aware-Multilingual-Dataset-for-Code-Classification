// Search Passport by Passport Number
const fs=require("fs");
// Search Passport by Passport Number
// Input: N, then N lines "passportNo|name|nationality|expiry", then target passportNo
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const targetPassport=lines[n+1]||"";
let found=false;
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[0]===targetPassport){console.log(lines[i]);found=true;break;}
}
if(!found)console.log("Passport Not Found");