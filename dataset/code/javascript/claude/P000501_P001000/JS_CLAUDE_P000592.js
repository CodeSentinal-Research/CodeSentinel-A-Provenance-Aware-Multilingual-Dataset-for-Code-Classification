const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);const val=+l[2];
console.log(a.filter(v=>v!==val).join(' '));
