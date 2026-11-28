// Valid Anagram after Removing One Character
const fs=require("fs");
const [a,b]=fs.readFileSync(0,"utf8").split(/\r?\n/).map(s=>s||"");
if(Math.abs(a.length-b.length)>1){console.log("No");process.exit();}
let i=0,j=0,edits=0;
while(i<a.length&&j<b.length){
  if(a[i]===b[j]){i++;j++;}
  else{
    edits++;
    if(edits>1)break;
    if(a.length>b.length)i++;
    else if(b.length>a.length)j++;
    else{i++;j++;}
  }
}
if(i<a.length||j<b.length)edits++;
console.log(edits<=1?"Yes":"No");