const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=[];
for(let i=0;i<n;i++)for(const x of l[i+1].split(' ').map(Number))a.push(x);
console.log(a.sort((x,y)=>x-y).join(' '));
