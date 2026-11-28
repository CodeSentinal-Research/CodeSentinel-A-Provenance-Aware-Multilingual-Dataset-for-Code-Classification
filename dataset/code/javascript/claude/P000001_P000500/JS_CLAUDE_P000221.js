const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const p=[];
for(let i=0;i<n;i++)p.push(l[i+1].split(' ').map(Number));
p.sort((a,b)=>a[1]-b[1]);let cnt=1,e=p[0][1];
for(let i=1;i<n;i++)if(p[i][0]>e){cnt++;e=p[i][1];}
console.log(cnt);
