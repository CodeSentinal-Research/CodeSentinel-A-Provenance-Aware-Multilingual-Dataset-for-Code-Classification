// Longest Repeating Character Replacement
const fs=require("fs");
const [s,k0]=fs.readFileSync(0,"utf8").trim().split(/\s+/),k=Number(k0),freq=new Map();let l=0,max=0,best=0;
for(let r=0;r<s.length;r++){freq.set(s[r],(freq.get(s[r])||0)+1);max=Math.max(max,freq.get(s[r]));while(r-l+1-max>k){freq.set(s[l],freq.get(s[l])-1);l++;}best=Math.max(best,r-l+1);}console.log(best);