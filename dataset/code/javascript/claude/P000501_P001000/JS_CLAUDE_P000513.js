const s=require('fs').readFileSync('/dev/stdin','utf8').trim();
let opens=0,closes=0;
for(const c of s){if(c==='(')opens++;else{if(opens>0)opens--;else closes++;}}
console.log(opens+closes);
