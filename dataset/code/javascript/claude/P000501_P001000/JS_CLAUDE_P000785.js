const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);const tot=a.reduce((s,v)=>s+v,0);
let left=0;for(let i=0;i<n;i++){if(left===tot-left-a[i]){console.log(i);process.exit();}left+=a[i];}console.log(-1);
