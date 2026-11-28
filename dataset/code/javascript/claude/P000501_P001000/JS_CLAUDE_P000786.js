const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);
const pre=new Array(n+1).fill(0);const suf=new Array(n+1).fill(0);
for(let i=0;i<n;i++)pre[i+1]=pre[i]+a[i];for(let i=n-1;i>=0;i--)suf[i]=suf[i+1]+a[i];
console.log(Array.from({length:n},(_,i)=>Math.abs(pre[i]-suf[i+1])).join(' '));
