// Group Anagrams
const fs=require("fs");
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const words=lines.slice(1,1+n);
const map=new Map();
for(const w of words){const k=[...w].sort().join("");if(!map.has(k))map.set(k,[]);map.get(k).push(w);}
for(const g of map.values())console.log(g.join(" "));