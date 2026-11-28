// Search Products Within Price Range
const fs=require("fs");
// Search Products Within Price Range
// Input: N, then N lines "code|name|price|qty", then minPrice maxPrice
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const [minP,maxP]=(lines[n+1]||"0 0").trim().split(/\s+/).map(Number);
const results=[];
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  const price=Number(parts[2]);
  if(price>=minP&&price<=maxP)results.push(lines[i]);
}
if(results.length)console.log(results.join("\n"));
else console.log("No Records Found");