// Count Character Occurrences
const fs=require("fs");const [s,c]=fs.readFileSync(0,"utf8").split(/\r?\n/);let n=0;for(const x of s)if(x===c)n++;console.log(n);