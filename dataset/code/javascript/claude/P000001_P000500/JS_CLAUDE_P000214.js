const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=parseInt(lines[0]);
const nums=lines[1].trim().split(' ').map(Number);
const seen=new Array(n+1).fill(false);
for(const x of nums) seen[x]=true;
const res=[];
for(let i=1;i<=n;i++) if(!seen[i]) res.push(i);
console.log(res.join(' '));
