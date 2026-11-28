// Remove All Adjacent Duplicates in String
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").trim(),st=[];for(const c of s)st.length&&st[st.length-1]===c?st.pop():st.push(c);console.log(st.join(""));