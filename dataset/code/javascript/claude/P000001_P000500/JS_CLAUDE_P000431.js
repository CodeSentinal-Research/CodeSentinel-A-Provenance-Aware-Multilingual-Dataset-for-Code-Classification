const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');const[n,x]=l[0].split(' ').map(Number);const a=l[1].split(' ').map(Number);console.log(a.filter(v=>v===x).length);
