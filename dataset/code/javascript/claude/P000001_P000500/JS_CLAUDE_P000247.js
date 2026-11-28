const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const[r,c]=l[0].split(' ').map(Number);
const A=[],B=[];
for(let i=0;i<r;i++)A.push(l[i+1].split(' ').map(Number));
for(let i=0;i<r;i++)B.push(l[r+i+1].split(' ').map(Number));
const same=A.every((row,i)=>row.every((v,j)=>v===B[i][j]));
console.log(same?'Identical':'Not Identical');
