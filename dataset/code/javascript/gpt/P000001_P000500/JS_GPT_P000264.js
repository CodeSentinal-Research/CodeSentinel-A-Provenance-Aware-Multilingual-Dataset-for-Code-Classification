// Count Frequency of Each Character
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").replace(/\r?\n$/,"");
const m=new Map();for(const c of s)m.set(c,(m.get(c)||0)+1);
console.log([...m].map(([c,n])=>c+" "+n).join("\n"));