const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const t=l[1].split(' ').map(Number);const ans=new Array(n).fill(0);const stk=[];
for(let i=0;i<n;i++){while(stk.length&&t[stk[stk.length-1]]<t[i]){const j=stk.pop();ans[j]=i-j;}stk.push(i);}
console.log(ans.join(' '));
