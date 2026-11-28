// Valid Palindrome II
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").trim();function pal(l,r){while(l<r)if(s[l++]!==s[r--])return false;return true;}let l=0,r=s.length-1;while(l<r&&s[l]===s[r]){l++;r--;}
console.log(l>=r||pal(l+1,r)||pal(l,r-1)?"Yes":"No");