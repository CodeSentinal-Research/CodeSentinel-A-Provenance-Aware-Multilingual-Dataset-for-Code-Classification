const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const[r1,c1,c2]=l[0].split(' ').map(Number);
const A=[],B=[];for(let i=0;i<r1;i++)A.push(l[i+1].split(' ').map(Number));
for(let i=0;i<c1;i++)B.push(l[r1+i+1].split(' ').map(Number));
for(let i=0;i<r1;i++){const row=new Array(c2).fill(0);for(let j=0;j<c2;j++)for(let k=0;k<c1;k++)row[j]+=A[i][k]*B[k][j];console.log(row.join(' '));}
