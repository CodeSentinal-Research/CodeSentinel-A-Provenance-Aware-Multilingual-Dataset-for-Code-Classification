const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number).sort((x,y)=>x-y);
const ans=Math.min(a[n-1]-a[2],a[n-2]-a[1],a[n-3]-a[0]);
console.log(Math.max(0,ans));
