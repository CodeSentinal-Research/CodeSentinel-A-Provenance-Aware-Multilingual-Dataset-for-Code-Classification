const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
let i=0;const k=+l[i++];const all=[];
for(let j=0;j<k;j++){const sz=+l[i++];all.push(...l[i++].split(' ').map(Number));}
all.sort((a,b)=>a-b);console.log(all.join(' '));
