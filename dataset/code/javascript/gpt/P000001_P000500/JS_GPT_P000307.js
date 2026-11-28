// Remove Invalid Parentheses
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").trim();
function valid(str){
  let c=0;
  for(const ch of str){if(ch==="(")c++;else if(ch===")"){c--;if(c<0)return false;}}
  return c===0;
}
const queue=[s],seen=new Set([s]),res=[];
let found=false;
while(queue.length){
  const cur=queue.shift();
  if(valid(cur)){res.push(cur);found=true;}
  if(found)continue;
  for(let i=0;i<cur.length;i++){
    if(cur[i]!=="("&&cur[i]!==")")continue;
    const nxt=cur.slice(0,i)+cur.slice(i+1);
    if(!seen.has(nxt)){seen.add(nxt);queue.push(nxt);}
  }
}
console.log(res.join("\n"));