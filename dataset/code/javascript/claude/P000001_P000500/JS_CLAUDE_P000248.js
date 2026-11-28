const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const[r,c]=l[0].split(' ').map(Number);
const A=[],B=[];for(let i=0;i<r;i++)A.push(l[i+1].split(' ').map(Number));
for(let i=0;i<r;i++)B.push(l[r+i+1].split(' ').map(Number));
for(let i=0;i<r;i++)console.log(A[i].map((v,j)=>v+B[i][j]).join(' '));
