const s=require("fs").readFileSync("/dev/stdin","utf8").trim();const seen=new Set();let r="";for(const c of s)if(!seen.has(c)){r+=c;seen.add(c);}console.log(r);
