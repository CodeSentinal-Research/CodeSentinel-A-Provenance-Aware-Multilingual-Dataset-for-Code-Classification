const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const[r,c,t]=l[0].split(' ').map(Number);
const A=[];for(let i=0;i<r;i++)A.push(l[i+1].split(' ').map(Number));
let i=0,j=c-1;
while(i<r&&j>=0){if(A[i][j]===t){console.log('Found');process.exit();}else if(A[i][j]>t)j--;else i++;}
console.log('Not Found');
