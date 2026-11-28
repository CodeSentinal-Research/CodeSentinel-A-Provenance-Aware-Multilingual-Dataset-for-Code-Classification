// Count and Say Sequence
const fs=require("fs");
const n=Number(fs.readFileSync(0,"utf8").trim());let cur="1";
for(let k=1;k<n;k++){let next="";for(let i=0;i<cur.length;){let j=i+1;while(j<cur.length&&cur[j]===cur[i])j++;next+=(j-i)+cur[i];i=j;}cur=next;}
console.log(cur);