const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);const res=[];
let lo=0,hi=n-1;while(lo<=hi){res.push(a[lo++]);if(lo<=hi)res.push(a[hi--]);}
console.log(res.join(' '));
