const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const[r,c]=l[0].split(' ').map(Number);
const A=[];for(let i=0;i<r;i++)A.push(l[i+1].split(' ').map(Number));
const kadane=a=>{let b=-Infinity,cur=0,mn=0;for(const x of a){cur+=x;b=Math.max(b,cur-mn);mn=Math.min(mn,cur);}return b;};
let best=-Infinity;
for(let li=0;li<c;li++){const row=new Array(r).fill(0);for(let ri=li;ri<c;ri++){for(let i=0;i<r;i++)row[i]+=A[i][ri];best=Math.max(best,kadane(row));}}
console.log(best);
