// Word Break II
const fs=require("fs");
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const s=lines[0]||"";
const dict=new Set(lines.slice(1).flatMap(l=>l.trim().split(/\s+/)).filter(Boolean));
const memo=new Map();
function dfs(start){
  if(memo.has(start))return memo.get(start);
  if(start===s.length)return [""];
  const res=[];
  for(let end=start+1;end<=s.length;end++){
    const word=s.slice(start,end);
    if(dict.has(word)){
      for(const sub of dfs(end)){
        res.push(sub?word+" "+sub:word);
      }
    }
  }
  memo.set(start,res);
  return res;
}
const ans=dfs(0);
for(const sent of ans)console.log(sent);