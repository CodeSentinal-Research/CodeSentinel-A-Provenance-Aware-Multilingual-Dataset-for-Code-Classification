const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const p=l[1].split(' ').map(Number);const res=[...p];const stk=[];
for(let i=0;i<n;i++){while(stk.length&&p[stk[stk.length-1]]>=p[i])res[stk.pop()]-=p[i];stk.push(i);}
console.log(res.join(' '));
