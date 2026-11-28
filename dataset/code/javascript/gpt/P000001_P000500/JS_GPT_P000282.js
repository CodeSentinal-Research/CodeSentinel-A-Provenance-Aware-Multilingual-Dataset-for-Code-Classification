// Longest Common Substring
const fs=require("fs");
const [a,b]=fs.readFileSync(0,"utf8").split(/\r?\n/);let prev=new Array(b.length+1).fill(0),best=0;
for(let i=1;i<=a.length;i++){const cur=new Array(b.length+1).fill(0);for(let j=1;j<=b.length;j++)if(a[i-1]===b[j-1]){cur[j]=prev[j-1]+1;best=Math.max(best,cur[j]);}prev=cur;}
console.log(best);