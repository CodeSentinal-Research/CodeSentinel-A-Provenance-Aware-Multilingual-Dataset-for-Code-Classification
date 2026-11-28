const s=require('fs').readFileSync('/dev/stdin','utf8').trim();
let res='';const stk=[];
for(const c of s){
    if(c==='(')stk.push(res.length);
    else if(c===')'){const st=stk.pop();res=res.slice(0,st)+res.slice(st).split('').reverse().join('');}
    else res+=c;
}console.log(res);
