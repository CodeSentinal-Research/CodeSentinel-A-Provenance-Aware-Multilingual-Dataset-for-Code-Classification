const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const M=[];
for(let i=0;i<n;i++)M.push(l[i+1].split(' ').map(Number));
let c=0;for(let i=1;i<n;i++)if(M[c][i])c=i;
for(let i=0;i<n;i++)if(i!==c&&(M[c][i]||!M[i][c])){console.log(-1);process.exit();}
console.log(c);
