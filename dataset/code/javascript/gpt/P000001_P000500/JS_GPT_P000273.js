// Valid Parentheses
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").trim(),pair={")":"(","]":"[","}":"{"},st=[];
let ok=true;
for(const c of s){if("([{".includes(c))st.push(c);else if(!st.length||st.pop()!==pair[c]){ok=false;break;}}
console.log(ok&&st.length===0?"Valid":"Invalid");