// Check Anagram
const fs=require("fs");
const [a,b]=fs.readFileSync(0,"utf8").split(/\r?\n/);
const f=s=>{const m=new Map();for(const c of s)m.set(c,(m.get(c)||0)+1);return m;};
const x=f(a||""),y=f(b||"");
let ok=(a||"").length===(b||"").length;
for(const [c,n] of x)if(y.get(c)!==n)ok=false;
console.log(ok?"Yes":"No");