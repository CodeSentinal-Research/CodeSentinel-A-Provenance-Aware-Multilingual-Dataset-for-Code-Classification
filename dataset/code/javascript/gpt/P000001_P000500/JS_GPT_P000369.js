// Search Empty String
const fs=require("fs");const l=fs.readFileSync(0,"utf8").split(/\r?\n/),n=Number(l[0]);let ans=-1;for(let i=0;i<n;i++)if((l[i+1]||"")===""){ans=i;break;}console.log(ans);