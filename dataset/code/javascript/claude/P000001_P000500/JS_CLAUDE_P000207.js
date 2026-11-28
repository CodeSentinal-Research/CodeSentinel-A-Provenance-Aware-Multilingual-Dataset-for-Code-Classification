const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const [r,c]=lines[0].trim().split(' ').map(Number);
const A=[];for(let i=0;i<r;i++) A.push(lines[i+1].trim().split(' ').map(Number));
let best=-Infinity;
for(let i=0;i+2<r;i++) for(let j=0;j+2<c;j++){
    const s=A[i][j]+A[i][j+1]+A[i][j+2]+A[i+1][j+1]+A[i+2][j]+A[i+2][j+1]+A[i+2][j+2];
    best=Math.max(best,s);
}
console.log(best);
