const s=require('fs').readFileSync('/dev/stdin','utf8').trim();let res=0;for(const c of s)res=res*26+(c.charCodeAt(0)-64);console.log(res);
