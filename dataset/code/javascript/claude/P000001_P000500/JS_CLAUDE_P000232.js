const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const[r,c]=l[0].split(' ').map(Number);const a=[];
for(let i=0;i<r;i++)for(const x of l[i+1].split(' ').map(Number))a.push(x);
a.sort((x,y)=>x-y);console.log(a[Math.floor((r*c)/2)]);
