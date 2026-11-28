const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const[r,c]=l[0].split(' ').map(Number);
const A=[];for(let i=0;i<r;i++)A.push(l[i+1].split(' ').map(Number));
for(let i=1;i<r;i++)for(let j=0;j<c;j++){let b=A[i-1][j];if(j>0)b=Math.max(b,A[i-1][j-1]);if(j<c-1)b=Math.max(b,A[i-1][j+1]);A[i][j]+=b;}
console.log(Math.max(...A[r-1]));
