// Add Bold Tag in String
const fs=require("fs");
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const s=lines[0]||"";
const words=lines.slice(1).flatMap(l=>l.trim().split(/\s+/)).filter(Boolean);
const bold=new Array(s.length).fill(false);
for(const w of words){
  let idx=0;
  while((idx=s.indexOf(w,idx))!==-1){
    for(let i=idx;i<idx+w.length;i++)bold[i]=true;
    idx++;
  }
}
let res="";
for(let i=0;i<s.length;i++){
  if(bold[i]&&(i===0||!bold[i-1]))res+="<b>";
  res+=s[i];
  if(bold[i]&&(i===s.length-1||!bold[i+1]))res+="</b>";
}
console.log(res);