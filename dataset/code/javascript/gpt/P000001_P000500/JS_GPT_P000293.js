// Encode and Decode Strings
const fs=require("fs");
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(x=>x.length>0);
let enc="";
for(const s of lines)enc+=s.length+"#"+s;
console.log(enc);
const dec=[];
let i=0;
while(i<enc.length){
  const pos=enc.indexOf("#",i);
  const len=Number(enc.slice(i,pos));
  dec.push(enc.slice(pos+1,pos+1+len));
  i=pos+1+len;
}
console.log(dec.join("\n"));