const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');const n=+l[0];const a=l[1].split(' ').map(Number);console.log(a.reduce((x,v)=>x^v,0));
