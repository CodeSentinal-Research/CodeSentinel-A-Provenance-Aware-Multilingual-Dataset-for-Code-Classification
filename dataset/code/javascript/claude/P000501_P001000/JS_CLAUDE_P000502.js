const tokens=require('fs').readFileSync('/dev/stdin','utf8').trim().split(/\s+/);
const stk=[];
for(const t of tokens){
    if(['+','-','*','/'].includes(t)){const b=stk.pop(),a=stk.pop();
    if(t==='+')stk.push(a+b);else if(t==='-')stk.push(a-b);else if(t==='*')stk.push(a*b);else stk.push(Math.trunc(a/b));}
    else stk.push(Number(t));
}console.log(stk[0]);
