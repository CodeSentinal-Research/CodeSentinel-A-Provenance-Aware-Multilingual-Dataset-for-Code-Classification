// Add Strings
const fs=require("fs");
const [a,b]=fs.readFileSync(0,"utf8").trim().split(/\s+/);let i=a.length-1,j=b.length-1,c=0,out=[];while(i>=0||j>=0||c){const v=(i>=0?+a[i--]:0)+(j>=0?+b[j--]:0)+c;out.push(v%10);c=Math.floor(v/10);}console.log(out.reverse().join(""));