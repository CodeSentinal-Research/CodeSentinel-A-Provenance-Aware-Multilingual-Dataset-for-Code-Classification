// Permutation in String
const fs=require("fs");
const [a,b]=fs.readFileSync(0,"utf8").split(/\r?\n/).map(s=>s||"");
if(a.length>b.length){console.log("No");process.exit();}
const f=s=>{const m=new Map();for(const c of s)m.set(c,(m.get(c)||0)+1);return m;};
const need=f(a),cur=new Map();
const match=()=>{if(need.size!==cur.size)return false;for(const [k,v] of need)if(cur.get(k)!==v)return false;return true;};
for(let i=0;i<a.length;i++)cur.set(b[i],(cur.get(b[i])||0)+1);
if(match()){console.log("Yes");process.exit();}
for(let i=a.length;i<b.length;i++){
  const r=b[i],l=b[i-a.length];
  cur.set(r,(cur.get(r)||0)+1);
  if(cur.get(l)===1)cur.delete(l);else cur.set(l,cur.get(l)-1);
  if(match()){console.log("Yes");process.exit();}
}
console.log("No");