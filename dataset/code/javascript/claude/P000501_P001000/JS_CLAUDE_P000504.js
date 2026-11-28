const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const res=new Array(n).fill(0);const stk=[];let prev=0;
for(let i=1;i<=n;i++){const[fid,typ,t]=l[i].split(':');const id=+fid,time=+t;
    if(typ==='start'){if(stk.length)res[stk[stk.length-1]]+=time-prev;stk.push(id);prev=time;}
    else{res[stk.pop()]+=time-prev+1;prev=time+1;}
}console.log(res.join(' '));
