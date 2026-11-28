// Shortest Distance to a Character
const fs=require("fs");
const [s,c]=fs.readFileSync(0,"utf8").split(/\r?\n/);const d=Array(s.length).fill(1e9);let last=-1e9;for(let i=0;i<s.length;i++){if(s[i]===c)last=i;if(last>-1e8)d[i]=i-last;}last=1e9;for(let i=s.length-1;i>=0;i--){if(s[i]===c)last=i;d[i]=Math.min(d[i],last-i);}console.log(d.join(" "));