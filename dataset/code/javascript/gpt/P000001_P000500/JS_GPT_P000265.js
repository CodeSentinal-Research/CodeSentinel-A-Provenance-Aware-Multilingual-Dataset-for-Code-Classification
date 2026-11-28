// Remove Duplicate Characters
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").replace(/\r?\n$/,"");
const seen=new Set(),out=[];for(const c of s)if(!seen.has(c)){seen.add(c);out.push(c);}
console.log(out.join(""));