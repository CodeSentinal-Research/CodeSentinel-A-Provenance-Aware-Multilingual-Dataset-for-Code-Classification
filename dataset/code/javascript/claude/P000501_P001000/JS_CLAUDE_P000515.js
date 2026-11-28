const s=require('fs').readFileSync('/dev/stdin','utf8').trim();
let d=0,mx=0;
for(const c of s){if(c==='('){d++;mx=Math.max(mx,d);}else if(c===')')d--;}
console.log(mx);
