// Longest Valid Parentheses
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").trim(),st=[-1];let best=0;for(let i=0;i<s.length;i++){if(s[i]==="(")st.push(i);else{st.pop();if(!st.length)st.push(i);else best=Math.max(best,i-st[st.length-1]);}}console.log(best);