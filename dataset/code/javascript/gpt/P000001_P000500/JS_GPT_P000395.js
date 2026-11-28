// Search Available Hotel Rooms
const fs=require("fs");
// Search Available Hotel Rooms
// Input: N, then N lines "roomNo|type|price|status", status="available"|"booked"
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const results=[];
for(let i=1;i<=n;i++){
  const parts=lines[i].split("|");
  if(parts[3]&&parts[3].toLowerCase()==="available")results.push(lines[i]);
}
if(results.length)console.log(results.join("\n"));
else console.log("No Records Found");