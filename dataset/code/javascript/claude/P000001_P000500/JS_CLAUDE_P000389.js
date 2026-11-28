const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];
const emps=l.slice(1,n+1).map(r=>r.trim());
const dept=l[n+1].trim();
const res=emps.filter(r=>r.split(' ')[1]===dept);
if(res.length) res.forEach(r=>console.log(r));
else console.log('No Records Found');
