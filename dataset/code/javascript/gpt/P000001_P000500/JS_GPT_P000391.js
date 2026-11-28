// Search Students Above Minimum GPA
const fs=require("fs");
// Search Students Above Minimum GPA
// Input: N, then N lines "rollNo|name|gpa|year", then minGpa
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const minGpa=Number(lines[n+1]||"0");
const results=[];
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  const gpa=Number(parts[2]);
  if(gpa>=minGpa)results.push(lines[i]);
}
if(results.length)console.log(results.join("\n"));
else console.log("No Records Found");