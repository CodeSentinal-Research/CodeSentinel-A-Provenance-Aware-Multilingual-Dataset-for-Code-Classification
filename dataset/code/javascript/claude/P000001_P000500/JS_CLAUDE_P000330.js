const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const s=lines[0];const wn=+lines[1];const words=lines.slice(2,2+wn);
const n=s.length,bold=new Array(n).fill(false);
for(const w of words){let idx=s.indexOf(w);while(idx>=0){for(let i=idx;i<idx+w.length;i++)bold[i]=true;idx=s.indexOf(w,idx+1);}}
let res='';for(let i=0;i<n;i++){if(bold[i]&&(i===0||!bold[i-1]))res+='<b>';res+=s[i];if(bold[i]&&(i===n-1||!bold[i+1]))res+='</b>';}
console.log(res);
