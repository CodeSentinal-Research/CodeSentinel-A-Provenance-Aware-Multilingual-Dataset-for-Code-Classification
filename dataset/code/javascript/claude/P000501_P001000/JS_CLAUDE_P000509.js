const s=require('fs').readFileSync('/dev/stdin','utf8').trim();const stk=[];
for(const c of s){if(c>='0'&&c<='9'){if(stk.length&&!(stk[stk.length-1]>='0'&&stk[stk.length-1]<='9'))stk.pop();}else stk.push(c);}
console.log(stk.join(''));
