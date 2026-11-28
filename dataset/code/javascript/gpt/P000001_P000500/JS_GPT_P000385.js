// Search Order by Order ID
const fs=require("fs");
// Search Order by Order ID
// Input: N, then N lines "orderId|customer|product|qty|status", then target orderId
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const targetOrder=lines[n+1]||"";
let found=false;
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[0]===targetOrder){console.log(lines[i]);found=true;break;}
}
if(!found)console.log("Order Not Found");