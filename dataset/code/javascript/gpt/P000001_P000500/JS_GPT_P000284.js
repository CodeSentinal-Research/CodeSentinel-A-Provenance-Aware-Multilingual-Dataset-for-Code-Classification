// Edit Distance
const fs=require("fs");
const [a,b]=fs.readFileSync(0,"utf8").split(/\r?\n/);let dp=Array.from({length:b.length+1},(_,i)=>i);
for(let i=1;i<=a.length;i++){const n=[i];for(let j=1;j<=b.length;j++)n[j]=Math.min(dp[j]+1,n[j-1]+1,dp[j-1]+(a[i-1]===b[j-1]?0:1));dp=n;}
console.log(dp[b.length]);