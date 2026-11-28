const[a,b]=require('fs').readFileSync('/dev/stdin','utf8').trim().split(' ');
console.log((BigInt(a)+BigInt(b)).toString());
