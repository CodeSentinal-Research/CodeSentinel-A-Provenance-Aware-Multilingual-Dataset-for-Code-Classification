const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const j=[];let md=0;
for(let i=0;i<n;i++){const[id,d,p]=l[i+1].split(' ').map(Number);j.push([id,d,p]);md=Math.max(md,d);}
j.sort((a,b)=>b[2]-a[2]);const slot=new Array(md+1).fill(-1);let cnt=0,prof=0;
for(const[id,d,p]of j)for(let t=d;t>0;t--)if(slot[t]===-1){slot[t]=id;cnt++;prof+=p;break;}
console.log(cnt+' '+prof);
