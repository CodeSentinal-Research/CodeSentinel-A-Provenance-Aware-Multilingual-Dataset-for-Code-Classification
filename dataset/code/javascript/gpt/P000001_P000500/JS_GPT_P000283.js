// Longest Common Subsequence Length
const fs=require("fs");
const [a,b]=fs.readFileSync(0,"utf8").split(/\r?\n/);let dp=new Array(b.length+1).fill(0);
for(let i=1;i<=a.length;i++){const next=dp.slice();for(let j=1;j<=b.length;j++)next[j]=a[i-1]===b[j-1]?dp[j-1]+1:Math.max(dp[j],next[j-1]);dp=next;}
console.log(dp[b.length]);