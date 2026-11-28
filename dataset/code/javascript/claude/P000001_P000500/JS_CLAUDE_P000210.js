const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=parseInt(lines[0]);
const a=lines[1].trim().split(' ').map(Number);
const b=lines[2].trim().split(' ').map(Number);
const c=lines[3].trim().split(' ').map(Number);
let i=0,j=0,k=0;const res=[];
while(i<n&&j<n&&k<n){
    if(a[i]===b[j]&&b[j]===c[k]){res.push(a[i]);i++;j++;k++;}
    else if(a[i]<=b[j]&&a[i]<=c[k]) i++;
    else if(b[j]<=a[i]&&b[j]<=c[k]) j++;
    else k++;
}
console.log(res.join(' '));
