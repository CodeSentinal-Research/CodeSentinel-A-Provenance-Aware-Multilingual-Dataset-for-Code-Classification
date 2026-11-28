// String Compression
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").replace(/\r?\n$/,"");let out="";
for(let i=0;i<s.length;){let j=i+1;while(j<s.length&&s[j]===s[i])j++;out+=s[i]+(j-i);i=j;}
console.log(out);