const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);const cnt={};
a.forEach(v=>cnt[v]=(cnt[v]||0)+1);console.log(a.filter(v=>cnt[v]===1).join(' '));
