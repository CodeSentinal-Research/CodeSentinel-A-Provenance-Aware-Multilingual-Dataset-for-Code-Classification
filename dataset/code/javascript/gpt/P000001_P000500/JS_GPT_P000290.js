// Find All Anagrams in a String
const fs=require("fs");
const [text,pat]=fs.readFileSync(0,"utf8").split(/\r?\n/);const need=new Map(),have=new Map();for(const c of pat)need.set(c,(need.get(c)||0)+1);let same=0,out=[];
for(let i=0;i<text.length;i++){const c=text[i];have.set(c,(have.get(c)||0)+1);if(have.get(c)===need.get(c))same++;if(i>=pat.length){const d=text[i-pat.length];if(have.get(d)===need.get(d))same--;have.set(d,have.get(d)-1);}if(i>=pat.length-1&&same===need.size)out.push(i-pat.length+1);}console.log(out.join(" "));