const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=parseInt(lines[0]);
const merged=[...lines[1].trim().split(' ').map(Number),...lines[2].trim().split(' ').map(Number)].sort((a,b)=>a-b);
const med=(merged[n-1]+merged[n])/2;
console.log(Number.isInteger(med)?med:med.toFixed(1));
