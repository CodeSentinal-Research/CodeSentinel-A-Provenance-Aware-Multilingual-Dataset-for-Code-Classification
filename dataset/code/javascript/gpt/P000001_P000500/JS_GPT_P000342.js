// Replace All Digits with Characters
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").trim();let out="";
for(let i=0;i<s.length;i++){
  if(/\d/.test(s[i]))out+=String.fromCharCode(s.charCodeAt(i-1)+Number(s[i]));
  else out+=s[i];
}
console.log(out);