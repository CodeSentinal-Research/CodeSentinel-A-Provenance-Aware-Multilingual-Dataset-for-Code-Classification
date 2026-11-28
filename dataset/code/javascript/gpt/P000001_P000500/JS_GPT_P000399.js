// Search Books Published After Given Year
const fs=require("fs");
// Search Books Published After Given Year
// Input: N, then N lines "isbn|title|author|year", then target year
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const afterYear=Number(lines[n+1]||"0");
const results=[];
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(Number(parts[3])>afterYear)results.push(lines[i]);
}
if(results.length)console.log(results.join("\n"));
else console.log("No Records Found");