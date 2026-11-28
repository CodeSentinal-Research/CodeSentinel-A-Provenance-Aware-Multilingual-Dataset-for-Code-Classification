// Search Contacts by Name Prefix
const fs=require("fs");
// Search Contacts by Name Prefix
// Input: N, then N lines "name|phone|email", then prefix
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const prefix=(lines[n+1]||"").toLowerCase();
const results=[];
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[0].toLowerCase().startsWith(prefix))results.push(lines[i]);
}
if(results.length)console.log(results.join("\n"));
else console.log("No Records Found");