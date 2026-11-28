const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const sa=new Set(l[1].split(' ').map(Number));
const m=+l[2];const b=l[3].split(' ').map(Number);
const inter=b.find(v=>sa.has(v));console.log(inter!==undefined?inter:'null');
