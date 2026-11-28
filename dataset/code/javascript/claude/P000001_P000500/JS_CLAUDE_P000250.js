const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const M=[];for(let i=0;i<n;i++)M.push(l[i+1].split(' ').map(Number));
let d=1;
for(let i=0;i<n;i++){let p=i;for(let k=i+1;k<n;k++)if(Math.abs(M[k][i])>Math.abs(M[p][i]))p=k;if(p!==i){[M[i],M[p]]=[M[p],M[i]];d*=-1;}if(M[i][i]===0){console.log(0);process.exit();}d*=M[i][i];for(let k=i+1;k<n;k++){const f=M[k][i]/M[i][i];for(let j=i;j<n;j++)M[k][j]-=f*M[i][j];}}
console.log(Math.round(d));
