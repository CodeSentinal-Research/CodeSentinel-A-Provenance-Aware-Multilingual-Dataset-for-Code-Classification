const s=require('fs').readFileSync('/dev/stdin','utf8').trim();
let cnt=0,opens=0;
for(const c of s){if(c==='[')opens++;else{if(opens>0)opens--;else cnt++;}}
console.log((cnt+1)>>1);
