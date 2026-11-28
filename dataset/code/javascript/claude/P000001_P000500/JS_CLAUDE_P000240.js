const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const[r,c]=l[0].split(' ').map(Number);
const A=[];for(let i=0;i<r;i++)A.push(l[i+1].split(' ').map(Number));
let s=A[0].reduce((a,b)=>a+b,0)+A[r-1].reduce((a,b)=>a+b,0);
for(let i=1;i<r-1;i++)s+=A[i][0]+A[i][c-1];
console.log(s);
