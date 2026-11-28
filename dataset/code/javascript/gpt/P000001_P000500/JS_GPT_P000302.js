// Word Break
const fs=require("fs");
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const s=lines[0]||"";
const dict=new Set(lines.slice(1).flatMap(l=>l.trim().split(/\s+/)).filter(Boolean));
const dp=new Array(s.length+1).fill(false);
dp[0]=true;
for(let i=1;i<=s.length;i++){
  for(let j=0;j<i;j++){
    if(dp[j]&&dict.has(s.slice(j,i))){dp[i]=true;break;}
  }
}
console.log(dp[s.length]?"Yes":"No");