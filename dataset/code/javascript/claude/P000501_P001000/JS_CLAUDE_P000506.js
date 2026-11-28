const s=require('fs').readFileSync('/dev/stdin','utf8').trim();
let idx=0;
function calc(){const stk=[];let num=0,sign='+';
    while(idx<s.length){const c=s[idx++];
        if(c>='0'&&c<='9')num=num*10+parseInt(c);
        else if(c==='(')num=calc();
        if((c<'0'||c>'9')&&c!==' '||idx===s.length){
            if(sign==='+')stk.push(num);else if(sign==='-')stk.push(-num);
            else if(sign==='*')stk.push(stk.pop()*num);
            else stk.push(Math.trunc(stk.pop()/num));
            if(c===')')break;sign=c;num=0;
        }
    }return stk.reduce((a,b)=>a+b,0);
}console.log(calc());
