const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const A=[];for(let i=0;i<n;i++)A.push(l[i+1].split(' ').map(Number));
for(let i=0;i<n;i++){const mn=Math.min(...A[i]);const jm=A[i].indexOf(mn);if(A.every(row=>row[jm]>=mn)){console.log(i+' '+jm+' '+mn);process.exit();}}
console.log('No Saddle Point');
