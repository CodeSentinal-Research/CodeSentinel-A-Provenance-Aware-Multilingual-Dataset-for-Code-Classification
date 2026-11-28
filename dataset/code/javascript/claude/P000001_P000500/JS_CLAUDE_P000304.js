const path=require('fs').readFileSync('/dev/stdin','utf8').trim();
const stk=[];
for(const p of path.split('/')){
    if(p==='..'){ if(stk.length)stk.pop(); }
    else if(p&&p!=='.')stk.push(p);
}
console.log('/'+stk.join('/'));
