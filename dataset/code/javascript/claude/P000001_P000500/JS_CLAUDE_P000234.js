const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const[r,c]=l[0].split(' ').map(Number);
const A=[];for(let i=0;i<r;i++)A.push(l[i+1].split(' ').map(Number));
const R=new Array(r).fill(false),C=new Array(c).fill(false);
for(let i=0;i<r;i++)for(let j=0;j<c;j++)if(A[i][j]){R[i]=C[j]=true;}
for(let i=0;i<r;i++)console.log(A[i].map((v,j)=>R[i]||C[j]?1:v).join(' '));
