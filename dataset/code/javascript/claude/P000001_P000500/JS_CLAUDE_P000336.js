const[a,b]=require('fs').readFileSync('/dev/stdin','utf8').trim().split(' ');
const palin=(s,l,r)=>{while(l<r)if(s[l++]!==s[r--])return false;return true;};
const check=(a,b)=>{let i=0,j=a.length-1;while(i<j&&a[i]===b[j]){i++;j--;}return palin(a,i,j)||palin(b,i,j);};
console.log(check(a,b)||check(b,a)?'Yes':'No');
