const[s,c]=require('fs').readFileSync('/dev/stdin','utf8').trim().split(' ');
const n=s.length,res=new Array(n).fill(n);let prev=-n;for(let i=0;i<n;i++){if(s[i]===c)prev=i;res[i]=i-prev;}prev=2*n;for(let i=n-1;i>=0;i--){if(s[i]===c)prev=i;res[i]=Math.min(res[i],prev-i);}console.log(res.join(' '));
