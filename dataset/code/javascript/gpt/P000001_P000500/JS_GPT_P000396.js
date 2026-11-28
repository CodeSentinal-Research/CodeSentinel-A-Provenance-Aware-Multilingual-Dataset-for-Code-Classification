// Search Active User Accounts
const fs=require("fs");
// Search Active User Accounts
// Input: N, then N lines "userId|username|email|status", status="active"|"inactive"
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const results=[];
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[3]&&parts[3].toLowerCase()==="active")results.push(lines[i]);
}
if(results.length)console.log(results.join("\n"));
else console.log("No Records Found");