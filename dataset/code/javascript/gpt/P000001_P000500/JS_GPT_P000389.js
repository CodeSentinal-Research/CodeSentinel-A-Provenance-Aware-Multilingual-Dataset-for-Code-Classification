// Search Employees by Department
const fs=require("fs");
// Search Employees by Department
// Input: N, then N lines "empId|name|dept|salary", then target dept
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const targetDept=(lines[n+1]||"").toLowerCase();
const results=[];
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[2]&&parts[2].toLowerCase()===targetDept)results.push(lines[i]);
}
if(results.length)console.log(results.join("\n"));
else console.log("No Records Found");