// Zigzag Conversion
const fs=require("fs");
const [s,rr]=fs.readFileSync(0,"utf8").split(/\r?\n/);const rows=Number(rr);if(rows===1||rows>=s.length){console.log(s);process.exit();}
const out=Array.from({length:rows},()=>"");let row=0,dir=1;for(const c of s){out[row]+=c;if(row===0)dir=1;else if(row===rows-1)dir=-1;row+=dir;}console.log(out.join(""));