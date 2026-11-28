const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];let cnt=0;
for(let i=0;i<n;i++)for(const x of l[i+1].split(' ').map(Number))if(x===0)cnt++;
console.log(cnt);
