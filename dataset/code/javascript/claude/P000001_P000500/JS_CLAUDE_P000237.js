const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const[r,c,k]=l[0].split(' ').map(Number);const sh=k%c;
for(let i=0;i<r;i++){const row=l[i+1].split(' ').map(Number);const out=[];for(let j=0;j<c;j++)out.push(row[(j+sh)%c]);console.log(out.join(' '));}
