// Search Customer by Mobile Number
const fs=require("fs");
// Search Customer by Mobile Number
// Input: N, then N lines "mobile|name|email|address", then target mobile
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const targetMobile=lines[n+1]||"";
let found=false;
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[0]===targetMobile){console.log(lines[i]);found=true;break;}
}
if(!found)console.log("Customer Not Found");