const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];for(let i=1;i<=n;i++)console.log(l[i].trim());
