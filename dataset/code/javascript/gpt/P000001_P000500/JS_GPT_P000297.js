// Roman to Integer
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").trim(),v={I:1,V:5,X:10,L:50,C:100,D:500,M:1000};let sum=0;for(let i=0;i<s.length;i++)sum+=v[s[i]]<(v[s[i+1]]||0)?-v[s[i]]:v[s[i]];console.log(sum);