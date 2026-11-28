// Determine if String Are Almost Equivalent
const fs=require("fs");
const [a,b]=fs.readFileSync(0,"utf8").split(/\r?\n/);const f=s=>{const m=new Map();for(const c of s)m.set(c,(m.get(c)||0)+1);return m;};const x=f(a),y=f(b);let ok=true;for(const c of new Set([...x.keys(),...y.keys()]))if(Math.abs((x.get(c)||0)-(y.get(c)||0))>3)ok=false;console.log(ok?"Yes":"No");