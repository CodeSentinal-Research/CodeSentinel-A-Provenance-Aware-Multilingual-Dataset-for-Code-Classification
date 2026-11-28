const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+lines[0];const rows=['qwertyuiop','asdfghjkl','zxcvbnm'];
for(let i=1;i<=n;i++){const w=lines[i].trim();const wl=w.toLowerCase();for(const r of rows){if([...wl].every(c=>r.includes(c))){console.log(w);break;}}}
