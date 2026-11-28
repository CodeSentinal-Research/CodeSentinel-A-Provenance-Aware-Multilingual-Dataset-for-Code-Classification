const s=require('fs').readFileSync('/dev/stdin','utf8').trim();const t=s+s;console.log(t.slice(1,-1).includes(s)?'Yes':'No');
