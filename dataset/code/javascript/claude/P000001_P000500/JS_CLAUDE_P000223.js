const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=[];
for(let i=0;i<n;i++)a.push(l[i+1].split(' ').map(Number));
a.sort((x,y)=>x[1]-y[1]);let cnt=1,e=a[0][1];
for(let i=1;i<n;i++)if(a[i][0]>=e){cnt++;e=a[i][1];}
console.log(cnt);
