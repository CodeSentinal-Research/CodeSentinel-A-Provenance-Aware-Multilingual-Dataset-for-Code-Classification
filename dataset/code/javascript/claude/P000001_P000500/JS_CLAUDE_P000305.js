const expr=require('fs').readFileSync('/dev/stdin','utf8').trim();
const stk=[];let num=0,sign=1,res=0;
for(const c of expr+' '){
    if(c>='0'&&c<='9')num=num*10+parseInt(c);
    else if(c==='+'||c==='-'){res+=sign*num;num=0;sign=c==='+'?1:-1;}
    else if(c==='('){stk.push(res);stk.push(sign);res=0;sign=1;}
    else if(c===')'){res+=sign*num;num=0;const s=stk.pop();res=res*s+stk.pop();sign=1;}
}
console.log(res);
