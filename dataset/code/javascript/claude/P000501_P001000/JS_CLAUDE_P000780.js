const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const a=l[1].split(' ').map(Number);let s=0;console.log(a.map(v=>(s+=v,s)).join(' '));
