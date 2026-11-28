const s=require('fs').readFileSync('/dev/stdin','utf8').trim();
const stk=[];let num=0,sign='+';
for(let i=0;i<=s.length;i++){const c=s[i]||'+';
    if(c>='0'&&c<='9')num=num*10+parseInt(c);
    else if(c!==' '){
        if(sign==='+')stk.push(num);else if(sign==='-')stk.push(-num);
        else if(sign==='*')stk.push(stk.pop()*num);
        else stk.push(Math.trunc(stk.pop()/num));
        sign=c;num=0;
    }
}console.log(stk.reduce((a,b)=>a+b,0));
