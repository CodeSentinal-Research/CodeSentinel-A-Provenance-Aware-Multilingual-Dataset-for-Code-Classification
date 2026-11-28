const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);const m=+l[2];const b=l[3].split(' ').map(Number);
const res=[...a,...b].sort((x,y)=>x-y);console.log(res.join(' '));
