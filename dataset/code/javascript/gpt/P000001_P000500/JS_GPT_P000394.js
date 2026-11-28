// Search Products by Brand Name
const fs=require("fs");
// Search Products by Brand Name
// Input: N, then N lines "code|name|brand|price", then target brand
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const targetBrand=(lines[n+1]||"").toLowerCase();
const results=[];
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[2]&&parts[2].toLowerCase()===targetBrand)results.push(lines[i]);
}
if(results.length)console.log(results.join("\n"));
else console.log("No Records Found");