// Camelcase Matching
const fs=require("fs");
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const pat=lines[lines.length-1];
const queries=lines.slice(0,lines.length-1).flatMap(l=>l.trim().split(/\s+/)).filter(Boolean);
function match(q,p){
  let i=0;
  for(const c of q){
    if(i<p.length&&c===p[i])i++;
    else if(c>='A'&&c<='Z')return false;
  }
  return i===p.length;
}
const ans=queries.map(q=>match(q,pat)?"true":"false");
console.log(ans.join(" "));