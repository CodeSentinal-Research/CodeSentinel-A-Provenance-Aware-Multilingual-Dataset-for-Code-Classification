// Count Occurrences of an Element
const fs=require("fs");const a=fs.readFileSync(0,"utf8").trim().split(/\s+/).map(Number),n=a[0],x=a[n+1];let c=0;for(let i=1;i<=n;i++)if(a[i]===x)c++;console.log(c);