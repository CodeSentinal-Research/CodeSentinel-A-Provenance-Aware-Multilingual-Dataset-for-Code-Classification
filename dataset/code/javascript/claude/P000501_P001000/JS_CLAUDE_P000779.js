const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
let i=0;const n=+l[i++];const a=l[i++].split(' ').map(Number);
const pre=new Array(n+1).fill(0);for(let j=0;j<n;j++)pre[j+1]=pre[j]+a[j];
const q=+l[i++];while(q-->0){const[lo,hi]=l[i++].split(' ').map(Number);console.log(pre[hi+1]-pre[lo]);}
