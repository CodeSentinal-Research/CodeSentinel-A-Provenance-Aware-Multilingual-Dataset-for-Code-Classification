// Search Positive Number
const fs=require("fs");const a=fs.readFileSync(0,"utf8").trim().split(/\s+/).map(Number),n=a[0];let ans=-1;for(let i=0;i<n;i++)if(a[i+1]>0){ans=i;break;}console.log(ans);