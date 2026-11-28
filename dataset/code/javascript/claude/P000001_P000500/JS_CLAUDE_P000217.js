const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=parseInt(lines[0]);
const a=lines[1].trim().split(' ').map(Number);
const total=a.reduce((s,x)=>s+x,0);
let left=0;
for(let i=0;i<n;i++){
    if(left===total-left-a[i]){console.log(i);process.exit();}
    left+=a[i];
}
console.log(-1);
