const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
let i=0;const[n,m]=l[i++].split(' ').map(Number);
const p=Array.from({length:n+1},()=>new Array(m+1).fill(0));
for(let r=1;r<=n;r++){const row=l[i++].split(' ').map(Number);for(let c=1;c<=m;c++)p[r][c]=row[c-1]+p[r-1][c]+p[r][c-1]-p[r-1][c-1];}
const q=+l[i++];for(let j=0;j<q;j++){const[r1,c1,r2,c2]=l[i++].split(' ').map(Number);console.log(p[r2+1][c2+1]-p[r1][c2+1]-p[r2+1][c1]+p[r1][c1]);}
