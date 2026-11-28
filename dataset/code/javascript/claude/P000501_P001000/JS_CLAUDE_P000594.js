const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);let k=+l[2]%n;
console.log([...a.slice(-k),...a.slice(0,-k)].join(' '));
