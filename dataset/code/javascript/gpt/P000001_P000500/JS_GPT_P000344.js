// Count Prefixes of a Given String
const fs=require("fs");
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const s=lines[lines.length-1];
const words=lines.slice(0,lines.length-1).flatMap(l=>l.trim().split(/\s+/)).filter(Boolean);
let count=0;
for(const w of words)if(s.startsWith(w))count++;
console.log(count);