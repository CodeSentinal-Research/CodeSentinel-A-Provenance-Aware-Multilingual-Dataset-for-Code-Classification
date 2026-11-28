// Search Invoice by Invoice Number
const fs=require("fs");
// Search Invoice by Invoice Number
// Input: N, then N lines "invoiceNo|client|amount|date", then target invoiceNo
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const targetInvoice=lines[n+1]||"";
let found=false;
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[0]===targetInvoice){console.log(lines[i]);found=true;break;}
}
if(!found)console.log("Invoice Not Found");