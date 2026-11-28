// Search Vehicles by Manufacturer
const fs=require("fs");
// Search Vehicles by Manufacturer
// Input: N, then N lines "regNo|manufacturer|model|year", then target manufacturer
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const targetMfr=(lines[n+1]||"").toLowerCase();
const results=[];
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[1]&&parts[1].toLowerCase()===targetMfr)results.push(lines[i]);
}
if(results.length)console.log(results.join("\n"));
else console.log("No Records Found");