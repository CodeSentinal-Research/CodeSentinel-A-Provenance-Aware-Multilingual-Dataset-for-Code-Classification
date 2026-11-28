const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const[n,k]=l[0].split(' ').map(Number);
const a=l[1].split(' ').map(Number);
let p=1;for(let i=n-k;i<n;i++)p*=a[i];
console.log(p);
