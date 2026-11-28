const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);const k=+l[2];
for(let i=0;i+k<=n;i+=k)a.splice(i,k,...a.slice(i,i+k).reverse());
console.log(a.join(' '));
