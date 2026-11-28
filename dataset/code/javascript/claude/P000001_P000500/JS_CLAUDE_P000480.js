const s=require('fs').readFileSync('/dev/stdin','utf8').trim();const stk=[];for(const c of s){if(stk.length&&stk[stk.length-1]===c)stk.pop();else stk.push(c);}console.log(stk.join(''));
