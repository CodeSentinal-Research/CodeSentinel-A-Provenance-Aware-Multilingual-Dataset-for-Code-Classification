const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);
function mc(a,lo,hi){
if(hi-lo<=1)return 0;
const m=(lo+hi)>>1;let inv=mc(a,lo,m)+mc(a,m,hi);
const tmp=[];let i=lo,j=m;
while(i<m&&j<hi){if(a[i]<=a[j])tmp.push(a[i++]);else{tmp.push(a[j++]);inv+=m-i;}}
while(i<m)tmp.push(a[i++]);while(j<hi)tmp.push(a[j++]);
for(let k=lo;k<hi;k++)a[k]=tmp[k-lo];return inv;}
console.log(mc(a,0,n));
