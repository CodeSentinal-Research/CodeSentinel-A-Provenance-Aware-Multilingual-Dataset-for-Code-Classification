const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const [n,k]=lines[0].trim().split(' ').map(Number);
const a=lines[1].trim().split(' ').map(Number);
let rem=k;
for(let i=0;i<n;i++)
    if(a[i]===0&&(i===0||a[i-1]===0)&&(i===n-1||a[i+1]===0)){a[i]=1;rem--;}
console.log(rem<=0?'true':'false');
