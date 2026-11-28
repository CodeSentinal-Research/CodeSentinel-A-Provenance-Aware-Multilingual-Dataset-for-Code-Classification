const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number).sort((x,y)=>x-y);
const d=l[2].split(' ').map(Number).sort((x,y)=>x-y);
let p=1,res=1,i=1,j=0;
while(i<n&&j<n){if(a[i]<=d[j]){p++;i++;}else{p--;j++;}res=Math.max(res,p);}
console.log(res);
