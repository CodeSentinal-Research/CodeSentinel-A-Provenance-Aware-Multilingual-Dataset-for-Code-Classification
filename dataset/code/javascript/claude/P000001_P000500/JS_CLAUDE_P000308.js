const expr=require('fs').readFileSync('/dev/stdin','utf8').trim();
function ways(s){
    const res=[];
    for(let i=0;i<s.length;i++){
        if('+-*'.indexOf(s[i])<0)continue;
        for(const l of ways(s.slice(0,i)))for(const r of ways(s.slice(i+1))){
            if(s[i]==='+')res.push(l+r);else if(s[i]==='-')res.push(l-r);else res.push(l*r);
        }
    }
    return res.length?res:[parseInt(s)];
}
console.log(ways(expr).sort((a,b)=>a-b).join(' '));
