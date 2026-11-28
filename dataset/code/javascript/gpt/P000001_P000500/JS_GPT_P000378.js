// Search Flight by Flight Number
const fs=require("fs");
// Search Flight by Flight Number
// Input: N, then N lines "flightNo|origin|destination|departure", then target flightNo
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const targetFlight=lines[n+1]||"";
let found=false;
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[0]===targetFlight){console.log(lines[i]);found=true;break;}
}
if(!found)console.log("Flight Not Found");