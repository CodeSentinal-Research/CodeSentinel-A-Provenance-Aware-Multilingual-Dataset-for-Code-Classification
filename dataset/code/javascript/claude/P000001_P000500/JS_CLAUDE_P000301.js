const s=require('fs').readFileSync('/dev/stdin','utf8').trim();
const res=[];
function bt(i,parts){
    if(parts.length===4){if(i===s.length)res.push(parts.join('.'));return;}
    for(let l=1;l<=3&&i+l<=s.length;l++){
        const seg=s.slice(i,i+l);
        if(seg[0]==='0'&&l>1)break;
        if(+seg>255)break;
        parts.push(seg);bt(i+l,parts);parts.pop();
    }
}
bt(0,[]);console.log(res.join('\n'));
