const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];
const mp={};
for(let i=1;i<=n;i++){const r=l[i].trim();mp[r.split(' ')[0]]=r;}
const q=l[n+1].trim();
console.log(mp[q]||'Record Not Found');
