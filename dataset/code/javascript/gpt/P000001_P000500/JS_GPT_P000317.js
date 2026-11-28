// Word Pattern
const fs=require("fs");
const [p,line]=fs.readFileSync(0,"utf8").split(/\r?\n/);const w=(line||"").trim().split(/\s+/).filter(Boolean),a=new Map(),b=new Map();let ok=p.length===w.length;for(let i=0;ok&&i<p.length;i++){if((a.has(p[i])&&a.get(p[i])!==w[i])||(b.has(w[i])&&b.get(w[i])!==p[i]))ok=false;a.set(p[i],w[i]);b.set(w[i],p[i]);}console.log(ok?"Yes":"No");