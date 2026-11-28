const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const s=lines[0];const n=+lines[1];let cnt=0;
const isSub=(w,s)=>{let i=0;for(const c of s)if(i<w.length&&c===w[i])i++;return i===w.length;};
for(let k=0;k<n;k++)if(isSub(lines[2+k].trim(),s))cnt++;console.log(cnt);
