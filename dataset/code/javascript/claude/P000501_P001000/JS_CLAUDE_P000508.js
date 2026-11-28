const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const h=l[1].split(' ').map(Number);const ans=new Array(n).fill(0);const stk=[];
for(let i=n-1;i>=0;i--){let cnt=0;
    while(stk.length&&stk[stk.length-1]<h[i]){stk.pop();cnt++;}
    if(stk.length)cnt++;ans[i]=cnt;stk.push(h[i]);}
console.log(ans.join(' '));
