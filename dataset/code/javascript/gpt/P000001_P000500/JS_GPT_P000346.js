// Find the Longest Word in Dictionary
const fs=require("fs");
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const s=lines[0]||"";
const words=lines.slice(1).flatMap(l=>l.trim().split(/\s+/)).filter(Boolean);
function isSubseq(w,target){
  let i=0;
  for(let j=0;j<target.length&&i<w.length;j++)if(w[i]===target[j])i++;
  return i===w.length;
}
let best="";
for(const w of words){
  if(isSubseq(w,s)){
    if(w.length>best.length||(w.length===best.length&&w<best))best=w;
  }
}
console.log(best);