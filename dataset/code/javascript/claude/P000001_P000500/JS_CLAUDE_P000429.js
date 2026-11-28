const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');const[n,x]=l[0].split(' ').map(Number);const a=l[1].split(' ').map(Number);const i=a.indexOf(x);console.log(i);
