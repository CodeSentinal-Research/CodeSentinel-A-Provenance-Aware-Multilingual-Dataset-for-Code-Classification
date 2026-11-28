const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);const lo=+l[2]-1,hi=+l[3]-1;
a.splice(lo,hi-lo+1,...a.slice(lo,hi+1).reverse());console.log(a.join(' '));
