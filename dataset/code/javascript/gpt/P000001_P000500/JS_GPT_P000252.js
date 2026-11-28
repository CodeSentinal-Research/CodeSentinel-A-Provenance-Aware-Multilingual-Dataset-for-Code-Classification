// Check if String is Palindrome
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").replace(/\r?\n$/,"");
let ok=true;
for(let l=0,r=s.length-1;l<r;l++,r--) if(s[l]!==s[r]){ok=false;break;}
console.log(ok?"Yes":"No");