const[a,b,t]=require('fs').readFileSync('/dev/stdin','utf8').trim().split(' ');const val=s=>BigInt([...s].map(c=>c.charCodeAt(0)-97).join(''));console.log(val(a)+val(b)===val(t)?'Yes':'No');
