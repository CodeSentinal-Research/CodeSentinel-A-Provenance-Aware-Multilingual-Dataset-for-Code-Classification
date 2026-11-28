// Search Hotel by Hotel ID
const fs=require("fs");
// Search Hotel by Hotel ID
// Input: N, then N lines "hotelId|name|city|stars", then target hotelId
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const targetId=lines[n+1]||"";
let found=false;
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[0]===targetId){console.log(lines[i]);found=true;break;}
}
if(!found)console.log("Hotel Not Found");