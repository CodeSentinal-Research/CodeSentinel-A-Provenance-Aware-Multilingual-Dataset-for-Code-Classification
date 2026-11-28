// Determine if String Halves Are Alike
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").trim().toLowerCase(),v="aeiou";let score=0;for(let i=0;i<s.length/2;i++){if(v.includes(s[i]))score++;if(v.includes(s[s.length/2+i]))score--;}console.log(score===0?"Yes":"No");