// Keyboard Row
const fs=require("fs");
const words=fs.readFileSync(0,"utf8").trim().split(/\s+/).filter(Boolean);
const r1=new Set("qwertyuiop"),r2=new Set("asdfghjkl"),r3=new Set("zxcvbnm");
const check=w=>{
  const s=w.toLowerCase();
  const r=r1.has(s[0])?r1:r2.has(s[0])?r2:r3;
  return [...s].every(c=>r.has(c));
};
const out=words.filter(check);
console.log(out.join("\n"));