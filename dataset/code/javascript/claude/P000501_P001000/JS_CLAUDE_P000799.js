const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
let i=0;const[n,m]=l[i++].split(' ').map(Number);
const g=[];for(let r=0;r<n;r++)g.push(l[i++].split(' ').map(Number));
const p=Array.from({length:n+1},()=>new Array(m+1).fill(0));
for(let r=1;r<=n;r++)for(let c=1;c<=m;c++)p[r][c]=g[r-1][c-1]+p[r-1][c]+p[r][c-1]-p[r-1][c-1];
for(let r=1;r<=n;r++)console.log(p[r].slice(1).join(' '));
