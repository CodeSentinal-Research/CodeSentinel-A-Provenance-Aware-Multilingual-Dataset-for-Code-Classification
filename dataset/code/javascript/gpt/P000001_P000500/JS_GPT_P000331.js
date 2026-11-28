// Exclusive Time of Functions
const fs=require("fs");
const lines=fs.readFileSync(0,"utf8").trim().split(/\r?\n/).filter(Boolean);
const n=Number(lines[0]);
const logs=lines.slice(1);
const res=new Array(n).fill(0);
const stack=[];
let prevTime=0;
for(const log of logs){
  const [idStr,type,timeStr]=log.split(":");
  const id=Number(idStr),time=Number(timeStr);
  if(type==="start"){
    if(stack.length)res[stack[stack.length-1]]+=time-prevTime;
    stack.push(id);
    prevTime=time;
  }else{
    res[stack.pop()]+=time-prevTime+1;
    prevTime=time+1;
  }
}
console.log(res.join(" "));