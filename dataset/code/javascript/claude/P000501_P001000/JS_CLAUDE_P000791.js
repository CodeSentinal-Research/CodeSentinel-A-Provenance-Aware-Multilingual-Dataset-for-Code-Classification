const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);const k=+l[2];
const pre=new Map([[0,-1]]);let s=0,best=0;
for(let i=0;i<n;i++){s+=a[i];if(pre.has(s-k))best=Math.max(best,i-pre.get(s-k));if(!pre.has(s))pre.set(s,i);}
console.log(best);
