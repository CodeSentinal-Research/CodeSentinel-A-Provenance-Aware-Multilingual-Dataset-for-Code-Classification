const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);const p=+l[2];
const tot=a.reduce((x,y)=>x+y,0);const r=tot%p;if(r===0){console.log(0);process.exit();}
const pre=new Map([[0,-1]]);let s=0,best=n;
for(let i=0;i<n;i++){s=(s+a[i])%p;const t=((s-r)%p+p)%p;if(pre.has(t)){const len=i-pre.get(t);if(len<n&&len<best)best=len;}if(!pre.has(s))pre.set(s,i);}
console.log(best===n?-1:best);
