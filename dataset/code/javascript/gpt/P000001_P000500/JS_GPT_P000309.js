// Multiply Strings
const fs=require("fs");
const [a,b]=fs.readFileSync(0,"utf8").trim().split(/\s+/);if(a==="0"||b==="0"){console.log("0");process.exit();}const z=Array(a.length+b.length).fill(0);for(let i=a.length-1;i>=0;i--)for(let j=b.length-1;j>=0;j--){const p=i+j+1,v=Number(a[i])*Number(b[j])+z[p];z[p]=v%10;z[p-1]+=Math.floor(v/10);}console.log(z.join("").replace(/^0+/,"")||"0");