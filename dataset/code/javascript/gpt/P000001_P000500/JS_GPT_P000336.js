// Split Two Strings to Make Palindrome
const fs=require("fs");
const [a,b]=fs.readFileSync(0,"utf8").split(/\r?\n/).map(s=>s||"");
const pal=(s,l,r)=>{while(l<r)if(s[l++]!==s[r--])return false;return true;};
function can(x,y){
  let l=0,r=x.length-1;
  while(l<r&&x[l]===y[r]){l++;r--;}
  return pal(x,l,r)||pal(y,l,r);
}
console.log(can(a,b)||can(b,a)?"Yes":"No");