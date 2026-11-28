// Decode String
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").trim(),stack=[];let num=0,cur="";
for(const c of s){if(/\d/.test(c))num=num*10+Number(c);else if(c==="["){stack.push([num,cur]);num=0;cur="";}else if(c==="]"){const [n,p]=stack.pop();cur=p+cur.repeat(n);}else cur+=c;}console.log(cur);