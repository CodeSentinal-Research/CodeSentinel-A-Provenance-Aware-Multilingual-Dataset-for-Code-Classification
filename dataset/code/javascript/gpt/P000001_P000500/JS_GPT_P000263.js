// Last Non-Repeating Character
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").replace(/\r?\n$/,"");
const m=new Map();for(const c of s)m.set(c,(m.get(c)||0)+1);
let ans=-1;for(let i=s.length-1;i>=0;i--)if(m.get(s[i])===1){ans=s[i];break;}
console.log(ans);