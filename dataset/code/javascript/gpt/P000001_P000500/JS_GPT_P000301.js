// Restore IP Addresses
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").trim(),out=[];const valid=x=>x.length&&x.length<=3&&!(x.length>1&&x[0]==="0")&&Number(x)<=255;function go(i,p){if(p.length===4){if(i===s.length)out.push(p.join("."));return;}for(let n=1;n<=3&&i+n<=s.length;n++){const x=s.slice(i,i+n);if(valid(x))go(i+n,p.concat(x));}}go(0,[]);console.log(out.join("\n"));