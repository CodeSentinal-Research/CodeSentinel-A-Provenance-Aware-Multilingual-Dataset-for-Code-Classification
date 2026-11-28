const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);
const idx=[...Array(n).keys()].sort((i,j)=>a[i]-a[j]);
const vis=new Array(n).fill(false);let sw=0;
for(let i=0;i<n;i++){if(vis[i]||idx[i]===i)continue;let j=i,c=0;while(!vis[j]){vis[j]=true;j=idx[j];c++;}sw+=c-1;}
console.log(sw);
