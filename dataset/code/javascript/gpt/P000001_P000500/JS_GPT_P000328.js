// First Unique Character in a String
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").trim(),m=new Map();for(const c of s)m.set(c,(m.get(c)||0)+1);let ans=-1;for(let i=0;i<s.length;i++)if(m.get(s[i])===1){ans=i;break;}console.log(ans);