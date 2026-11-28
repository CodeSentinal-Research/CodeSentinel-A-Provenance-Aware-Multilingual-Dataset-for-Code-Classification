// Isomorphic Strings
const fs=require("fs");
const [a,b]=fs.readFileSync(0,"utf8").split(/\r?\n/);const ab=new Map(),ba=new Map();let ok=a.length===b.length;for(let i=0;ok&&i<a.length;i++){if((ab.has(a[i])&&ab.get(a[i])!==b[i])||(ba.has(b[i])&&ba.get(b[i])!==a[i]))ok=false;ab.set(a[i],b[i]);ba.set(b[i],a[i]);}console.log(ok?"Yes":"No");