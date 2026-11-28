const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+lines[0],m=+lines[1];const res=new Array(n).fill(0);const stk=[];let prev=0;
for(let k=0;k<m;k++){const[fid,typ,time]=lines[2+k].split(':');const f=+fid,t=+time;if(typ==='start'){if(stk.length)res[stk[stk.length-1]]+=t-prev;stk.push(f);prev=t;}else{res[stk.pop()]+=t-prev+1;prev=t+1;}}
console.log(res.join(' '));
