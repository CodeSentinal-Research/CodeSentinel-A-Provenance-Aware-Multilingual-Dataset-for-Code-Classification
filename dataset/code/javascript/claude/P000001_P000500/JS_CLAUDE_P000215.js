const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const [n,k]=lines[0].trim().split(' ').map(Number);
const a=lines[1].trim().split(' ').map(Number);
let win=a.slice(0,k).reduce((s,x)=>s+x,0),best=win;
for(let i=k;i<n;i++){win+=a[i]-a[i-k];best=Math.max(best,win);}
console.log((best/k).toFixed(5));
