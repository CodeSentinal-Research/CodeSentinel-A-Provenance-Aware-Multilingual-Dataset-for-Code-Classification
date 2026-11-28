// Custom Sort String
const fs=require("fs");
const [order,s]=fs.readFileSync(0,"utf8").split(/\r?\n/);const m=new Map();for(const c of s)m.set(c,(m.get(c)||0)+1);let out="";for(const c of order){out+=c.repeat(m.get(c)||0);m.delete(c);}for(const [c,n] of m)out+=c.repeat(n);console.log(out);