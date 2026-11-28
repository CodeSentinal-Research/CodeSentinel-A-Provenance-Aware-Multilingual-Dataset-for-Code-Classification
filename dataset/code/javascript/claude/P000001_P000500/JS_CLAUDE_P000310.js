const[a,b]=require('fs').readFileSync('/dev/stdin','utf8').trim().split(' ');
console.log((BigInt('0b'+a)+BigInt('0b'+b)).toString(2));
