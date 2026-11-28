const s=require('fs').readFileSync('/dev/stdin','utf8').trim();const stk=[];let cur='',num=0;
for(const c of s){
    if(c>='0'&&c<='9')num=num*10+parseInt(c);
    else if(c==='['){stk.push([cur,num]);cur='';num=0;}
    else if(c===']'){const[prev,n]=stk.pop();cur=prev+cur.repeat(n);}
    else cur+=c;
}
console.log(cur);
