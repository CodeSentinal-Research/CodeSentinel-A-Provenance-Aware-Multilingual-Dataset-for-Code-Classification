// Search Employees by Salary Range
const fs=require("fs");
// Search Employees by Salary Range
// Input: N, then N lines "empId|name|dept|salary", then minSalary maxSalary
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const [minS,maxS]=(lines[n+1]||"0 0").trim().split(/\s+/).map(Number);
const results=[];
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  const salary=Number(parts[3]);
  if(salary>=minS&&salary<=maxS)results.push(lines[i]);
}
if(results.length)console.log(results.join("\n"));
else console.log("No Records Found");