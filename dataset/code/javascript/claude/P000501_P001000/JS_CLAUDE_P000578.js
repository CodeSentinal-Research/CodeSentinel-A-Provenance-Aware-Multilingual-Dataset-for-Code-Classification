/* P000578: Binary Tree Top View */
const toks=require('fs').readFileSync('/dev/stdin','utf8').trim().split(' ');
const n=toks.length;const val=[];const has=[];
for(let i=0;i<n;i++){if(toks[i]==='null'){has.push(false);val.push(0);}else{has.push(true);val.push(+toks[i]);}}
if(!n||!has[0])process.exit();
const q=[[0,0,0]];const top={};let qi=0;
while(qi<q.length){const[idx,lev,hd]=q[qi++];if(idx>=n||!has[idx])continue;
    if(!(hd in top))top[hd]=val[idx];
    if(2*idx+1<n)q.push([2*idx+1,lev+1,hd-1]);if(2*idx+2<n)q.push([2*idx+2,lev+1,hd+1]);}
console.log(Object.keys(top).sort((a,b)=>+a-+b).map(k=>top[k]).join(' '));
