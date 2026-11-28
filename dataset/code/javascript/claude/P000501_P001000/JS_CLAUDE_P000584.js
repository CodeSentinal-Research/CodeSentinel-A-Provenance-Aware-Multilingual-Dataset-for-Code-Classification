const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const sz=+l[0];const a=l[1].split(' ').map(Number);const n=+l[2];
a.splice(sz-n,1);console.log(a.join(' '));
