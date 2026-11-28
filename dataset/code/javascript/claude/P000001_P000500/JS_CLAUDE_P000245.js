const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const A=[];for(let i=0;i<n;i++)A.push(l[i+1].split(' ').map(Number));
for(let i=0;i<n;i++)console.log(A[i].map((v,j)=>j<=i?v:0).join(' '));
