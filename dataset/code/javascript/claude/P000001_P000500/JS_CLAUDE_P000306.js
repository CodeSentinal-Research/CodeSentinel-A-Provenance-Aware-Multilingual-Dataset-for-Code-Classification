const expr=require('fs').readFileSync('/dev/stdin','utf8').trim().replace(/ /g,'');
const stk=[];let num=0,op='+';
for(let i=0;i<=expr.length;i++){
    const c=i<expr.length?expr[i]:null;
    if(c&&c>='0'&&c<='9')num=num*10+parseInt(c);
    if(!c||!(c>='0'&&c<='9')){
        if(op==='+')stk.push(num);
        else if(op==='-')stk.push(-num);
        else if(op==='*'){const t=stk.pop();stk.push(t*num);}
        else{const t=stk.pop();stk.push(t<0?-Math.floor(-t/num):Math.floor(t/num));}
        op=c;num=0;
    }
}
console.log(stk.reduce((a,b)=>a+b,0));
