const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];
const orders=l.slice(1,n+1).map(r=>r.trim());
const status=l[n+1].trim();
const res=orders.filter(r=>r.split(' ')[1]===status);
if(res.length) res.forEach(r=>console.log(r));
else console.log('No Orders Found');
