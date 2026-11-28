const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=parseInt(lines[0]);
const a=lines[1].trim().split(' ').map(Number).sort((x,y)=>x-y);
for(let i=0;i+1<n;i+=2){[a[i],a[i+1]]=[a[i+1],a[i]];}
console.log(a.join(' '));
