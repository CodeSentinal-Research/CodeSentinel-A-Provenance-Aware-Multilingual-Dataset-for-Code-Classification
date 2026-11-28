// Search Contact by Name
const fs=require("fs");
// Search Contact by Name
// Input: N, then N lines "name|phone|email", then target name
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const targetName=(lines[n+1]||"").toLowerCase();
const results=[];
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[0].toLowerCase()===targetName)results.push(lines[i]);
}
if(results.length)console.log(results.join("\n"));
else console.log("Contact Not Found");