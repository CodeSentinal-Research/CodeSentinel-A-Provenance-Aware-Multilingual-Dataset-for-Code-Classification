// Maximum Score After Splitting a String
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").trim();let ones=0;for(const c of s)if(c==="1")ones++;let z=0,best=0;for(let i=0;i<s.length-1;i++){if(s[i]==="0")z++;else ones--;best=Math.max(best,z+ones);}console.log(best);