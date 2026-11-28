// Longest Palindromic Substring
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").replace(/\r?\n$/,"");let best="";
function expand(l,r){while(l>=0&&r<s.length&&s[l]===s[r]){l--;r++;}return s.slice(l+1,r);}
for(let i=0;i<s.length;i++){const a=expand(i,i),b=expand(i,i+1);if(a.length>best.length)best=a;if(b.length>best.length)best=b;}
console.log(best);