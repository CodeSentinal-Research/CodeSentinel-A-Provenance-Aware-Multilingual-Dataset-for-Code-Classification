// Search Email by Username
const fs=require("fs");
// Search Email by Username
// Input: N, then N lines "username|email|fullName", then target username
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const targetUser=lines[n+1]||"";
let found=false;
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[0]===targetUser){console.log(parts[1]);found=true;break;}
}
if(!found)console.log("User Not Found");