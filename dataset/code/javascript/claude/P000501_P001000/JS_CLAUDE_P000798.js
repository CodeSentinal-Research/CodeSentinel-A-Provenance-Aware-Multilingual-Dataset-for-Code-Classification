const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);
const pre=new Map([[0,-1]]);let s=0,best=0;
for(let i=0;i<n;i++){s+=(a[i]===1?1:-1);if(pre.has(s))best=Math.max(best,i-pre.get(s));else pre.set(s,i);}console.log(best);
