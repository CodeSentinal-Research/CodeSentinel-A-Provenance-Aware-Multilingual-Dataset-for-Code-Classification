const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const[r,c]=l[0].split(' ').map(Number);
let br=-1,bc=-1;
for(let i=0;i<r;i++){const cnt=l[i+1].split(' ').map(Number).reduce((s,x)=>s+x,0);if(cnt>bc){bc=cnt;br=i;}}
console.log(br);
