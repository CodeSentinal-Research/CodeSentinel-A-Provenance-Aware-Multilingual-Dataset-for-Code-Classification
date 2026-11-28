const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);const k=+l[2];
const seen=new Map([[0,-1]]);let s=0;
for(let i=0;i<n;i++){s=((s+a[i])%k+k)%k;if(seen.has(s)&&i-seen.get(s)>=2){console.log('true');process.exit();}if(!seen.has(s))seen.set(s,i);}
console.log('false');
