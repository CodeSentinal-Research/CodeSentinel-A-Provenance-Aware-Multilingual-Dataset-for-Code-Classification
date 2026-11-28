// String to Integer (atoi)
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").trimStart();let i=0,sign=1;if(s[i]==="+"||s[i]==="-"){if(s[i]==="-")sign=-1;i++;}let n=0;
while(i<s.length&&/\d/.test(s[i])){n=n*10+Number(s[i++]);if(n>2147483648)n=2147483648;}
let val=sign*n;if(val>2147483647)val=2147483647;if(val<-2147483648)val=-2147483648;
console.log(val);