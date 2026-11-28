const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=parseInt(lines[0]);
const a=lines[1].trim().split(' ').map(Number);
const freq={},first={},last={};
for(let i=0;i<n;i++){const x=a[i];freq[x]=(freq[x]||0)+1;if(!(x in first))first[x]=i;last[x]=i;}
const deg=Math.max(...Object.values(freq));
let res=n;
for(const x in freq) if(freq[x]===deg) res=Math.min(res,last[x]-first[x]+1);
console.log(res);
