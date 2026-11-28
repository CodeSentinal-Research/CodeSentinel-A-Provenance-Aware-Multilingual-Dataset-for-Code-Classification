// Longest Substring Without Repeating Characters
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").replace(/\r?\n$/,"");const last=new Map();let left=0,best=0;
for(let i=0;i<s.length;i++){if(last.has(s[i])&&last.get(s[i])>=left)left=last.get(s[i])+1;last.set(s[i],i);best=Math.max(best,i-left+1);}
console.log(best);