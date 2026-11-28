const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);const k=+l[2];
let s=a.slice(0,k).reduce((x,y)=>x+y,0),best=s;
for(let i=k;i<n;i++){s+=a[i]-a[i-k];if(s>best)best=s;}
console.log(best/k);
