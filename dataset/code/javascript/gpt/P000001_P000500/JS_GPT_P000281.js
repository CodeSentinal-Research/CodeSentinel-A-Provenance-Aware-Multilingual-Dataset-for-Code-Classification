// Minimum Window Substring
const fs=require("fs");
const [s,t]=fs.readFileSync(0,"utf8").split(/\r?\n/);const need=new Map();for(const c of t)need.set(c,(need.get(c)||0)+1);
let missing=t.length,left=0,start=0,len=Infinity;
for(let r=0;r<s.length;r++){const c=s[r];if(need.has(c)){if(need.get(c)>0)missing--;need.set(c,need.get(c)-1);}while(missing===0){if(r-left+1<len){len=r-left+1;start=left;}const d=s[left++];if(need.has(d)){need.set(d,need.get(d)+1);if(need.get(d)>0)missing++;}}}
console.log(len===Infinity?"":s.slice(start,start+len));