// Search Files by Extension
const fs=require("fs");
// Search Files by Extension
// Input: N, then N file names, then target extension (with or without dot)
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
let ext=lines[n+1]||"";
if(!ext.startsWith("."))ext="."+ext;
const results=[];
for(let i=1;i<=n;i++){
  if(lines[i].endsWith(ext))results.push(lines[i]);
}
if(results.length)console.log(results.join("\n"));
else console.log("No Records Found");