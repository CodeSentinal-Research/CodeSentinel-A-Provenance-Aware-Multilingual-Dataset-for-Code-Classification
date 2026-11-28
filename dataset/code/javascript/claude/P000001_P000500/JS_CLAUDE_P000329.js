const[s,t]=require('fs').readFileSync('/dev/stdin','utf8').trim().split(' ');let d=0;for(const c of s+t)d^=c.charCodeAt(0);console.log(String.fromCharCode(d));
