const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const s=lines[0].trim();const ws=new Set(lines[1].trim().split(' '));
const res=[];
function bt(i,path){
    if(i===s.length){res.push(path);return;}
    for(let j=i+1;j<=s.length;j++){const w=s.slice(i,j);if(ws.has(w))bt(j,path?path+' '+w:w);}
}
bt(0,'');console.log(res.join('\n'));
