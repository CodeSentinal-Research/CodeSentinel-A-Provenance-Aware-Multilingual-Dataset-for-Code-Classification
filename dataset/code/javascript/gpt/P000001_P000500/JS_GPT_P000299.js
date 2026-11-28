// Generate Parentheses
const fs=require("fs");
const n=Number(fs.readFileSync(0,"utf8").trim()),out=[];function go(s,o,c){if(s.length===2*n){out.push(s);return;}if(o<n)go(s+"(",o+1,c);if(c<o)go(s+")",o,c+1);}go("",0,0);console.log(out.join("\n"));