// Search Maximum Value
const fs=require("fs");const a=fs.readFileSync(0,"utf8").trim().split(/\s+/).map(Number),n=a[0];let ans=0;for(let i=1;i<n;i++)if(a[i+1]>a[ans+1])ans=i;console.log(ans);