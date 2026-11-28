const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];
const recs=l.slice(1,n+1).map(r=>r.trim());
const cutoff=l[n+1].trim();
const res=recs.filter(r=>r.split(' ').slice(-1)[0]<cutoff);
if(res.length) res.forEach(r=>console.log(r));
else console.log('No Employees Found');
