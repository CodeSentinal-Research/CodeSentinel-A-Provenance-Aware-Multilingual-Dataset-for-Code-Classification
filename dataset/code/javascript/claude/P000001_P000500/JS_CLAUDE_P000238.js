const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const A=[];for(let i=0;i<n;i++)A.push(l[i+1].split(' ').map(Number));
let ok=true;
for(let i=0;i<n&&ok;i++)for(let j=0;j<n&&ok;j++){let d=0;for(let k=0;k<n;k++)d+=A[i][k]*A[j][k];if(Math.abs(d-(i===j?1:0))>1e-6)ok=false;}
console.log(ok?'Yes':'No');
