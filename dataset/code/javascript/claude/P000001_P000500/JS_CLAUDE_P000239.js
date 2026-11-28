const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const[r,c]=l[0].split(' ').map(Number);
const A=[];for(let i=0;i<r;i++)A.push(l[i+1].split(' ').map(Number));
const res=[];
for(let j=0;j<c;j++)res.push(A[0][j]);
for(let i=1;i<r-1;i++){res.push(A[i][0]);res.push(A[i][c-1]);}
if(r>1)for(let j=0;j<c;j++)res.push(A[r-1][j]);
console.log(res.join(' '));
