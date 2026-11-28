const s=require('fs').readFileSync('/dev/stdin','utf8').trim();const f={};for(const c of s)f[c]=(f[c]||0)+1;for(let i=0;i<s.length;i++)if(f[s[i]]===1){console.log(i);process.exit();}console.log(-1);
