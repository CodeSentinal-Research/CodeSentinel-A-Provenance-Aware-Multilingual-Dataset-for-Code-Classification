// Search Orders by Order Status
const fs=require("fs");
// Search Orders by Order Status
// Input: N, then N lines "orderId|customer|product|status", then target status
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const targetStatus=(lines[n+1]||"").toLowerCase();
const results=[];
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[3]&&parts[3].toLowerCase()===targetStatus)results.push(lines[i]);
}
if(results.length)console.log(results.join("\n"));
else console.log("No Records Found");