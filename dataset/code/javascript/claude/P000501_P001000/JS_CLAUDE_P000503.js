const s=require('fs').readFileSync('/dev/stdin','utf8').trim();
const stk=[0];
for(const c of s){
    if(c==='(')stk.push(0);
    else{const v=stk.pop();stk[stk.length-1]+=v?2*v:1;}
}console.log(stk[0]);
