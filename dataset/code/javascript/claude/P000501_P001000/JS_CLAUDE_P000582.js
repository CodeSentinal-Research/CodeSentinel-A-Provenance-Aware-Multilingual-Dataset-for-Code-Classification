const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);
const res=a.filter((v,i)=>i===0||v!==a[i-1]);console.log(res.join(' '));
