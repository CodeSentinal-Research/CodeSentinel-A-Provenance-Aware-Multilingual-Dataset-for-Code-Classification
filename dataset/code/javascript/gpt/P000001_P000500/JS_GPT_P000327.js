// Ransom Note
const fs=require("fs");
const [r,m]=fs.readFileSync(0,"utf8").split(/\r?\n/);const f=new Map();for(const c of m)f.set(c,(f.get(c)||0)+1);let ok=true;for(const c of r){if(!(f.get(c)>0)){ok=false;break;}f.set(c,f.get(c)-1);}console.log(ok?"Yes":"No");