const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);const s=[...a].sort((x,y)=>x-y);
let lo=0,hi=n-1;while(lo<n&&a[lo]===s[lo])lo++;while(hi>=0&&a[hi]===s[hi])hi--;
console.log(lo>hi?0:hi-lo+1);
