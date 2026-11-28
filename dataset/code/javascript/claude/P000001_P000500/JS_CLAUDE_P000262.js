const s=require("fs").readFileSync("/dev/stdin","utf8").trim();const f={};for(const c of s)f[c]=(f[c]||0)+1;for(const c of s)if(f[c]===1){console.log(c);process.exit();}console.log(-1);
