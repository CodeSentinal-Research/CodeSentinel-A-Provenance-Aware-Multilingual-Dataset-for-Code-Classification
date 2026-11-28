const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const [m,n]=lines[0].trim().split(' ').map(Number);
const merged=[...lines[1].trim().split(' ').map(Number),...lines[2].trim().split(' ').map(Number)].sort((a,b)=>a-b);
const total=m+n;
if(total%2===1) console.log(merged[Math.floor(total/2)]);
else{const med=(merged[total/2-1]+merged[total/2])/2;console.log(Number.isInteger(med)?med:med.toFixed(1));}
