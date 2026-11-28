const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);let tot=0;
for(let i=0;i<n;i++){let mn=a[i],mx=a[i];for(let j=i;j<n;j++){mn=Math.min(mn,a[j]);mx=Math.max(mx,a[j]);tot+=mx-mn;}}
console.log(tot);
