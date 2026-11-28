// Search Transaction by Transaction ID
const fs=require("fs");
// Search Transaction by Transaction ID
// Input: N, then N lines "txnId|type|amount|date|status", then target txnId
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const targetTxn=lines[n+1]||"";
let found=false;
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[0]===targetTxn){console.log(lines[i]);found=true;break;}
}
if(!found)console.log("Transaction Not Found");