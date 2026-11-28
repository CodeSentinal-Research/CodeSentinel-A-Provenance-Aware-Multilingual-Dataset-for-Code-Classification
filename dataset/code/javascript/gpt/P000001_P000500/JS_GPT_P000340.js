// Maximum Number of Words You Can Type
const fs=require("fs");
const [text,broken]=fs.readFileSync(0,"utf8").split(/\r?\n/),bad=new Set(broken||"");let n=0;for(const w of (text||"").split(/\s+/))if(w&&[...w].every(c=>!bad.has(c)))n++;console.log(n);