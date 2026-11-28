const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
let i=0;const n=+l[i++];const a=l[i++].split(' ').map(Number);const q=+l[i++];
while(q-->0){const[lo,hi]=l[i++].split(' ').map(Number);console.log(a.filter(v=>v>=lo&&v<=hi).length);}
