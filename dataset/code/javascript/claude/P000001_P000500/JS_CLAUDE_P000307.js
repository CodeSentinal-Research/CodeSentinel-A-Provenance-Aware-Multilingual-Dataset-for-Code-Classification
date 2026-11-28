const s=require('fs').readFileSync('/dev/stdin','utf8').trim();
const valid=t=>{let c=0;for(const x of t){if(x==='(')c++;else if(x===')')if(--c<0)return false;}return c===0;};
const vis=new Set([s]);const q=[s];const res=[];let found=false;
while(q.length){
    const cur=q.shift();
    if(valid(cur)){res.push(cur);found=true;}
    if(found)continue;
    for(let i=0;i<cur.length;i++){
        if(cur[i]!=='('&&cur[i]!==')')continue;
        const nxt=cur.slice(0,i)+cur.slice(i+1);
        if(!vis.has(nxt)){vis.add(nxt);q.push(nxt);}
    }
}
console.log(res.join('\n'));
