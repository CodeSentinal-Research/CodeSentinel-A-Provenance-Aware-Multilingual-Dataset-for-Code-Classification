const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);const val=+l[2];
const idx=a.indexOf(val);if(idx!==-1)a.splice(idx,1);console.log(a.join(' '));
