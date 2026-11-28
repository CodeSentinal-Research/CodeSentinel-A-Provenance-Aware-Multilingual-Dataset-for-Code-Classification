// Search Train by Train Number
const fs=require("fs");
// Search Train by Train Number
// Input: N, then N lines "trainNo|name|source|destination", then target trainNo
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const targetTrain=lines[n+1]||"";
let found=false;
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[0]===targetTrain){console.log(lines[i]);found=true;break;}
}
if(!found)console.log("Train Not Found");