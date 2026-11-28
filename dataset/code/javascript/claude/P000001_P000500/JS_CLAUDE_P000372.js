const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];
const recs=l.slice(1,n+1).map(r=>r.trim());
const roll=l[n+1].trim();
const found=recs.find(r=>r.split(' ')[0]===roll);
console.log(found||'Record Not Found');
