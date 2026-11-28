// Remove All Adjacent Duplicates in String II
const fs=require("fs");
const [s,k0]=fs.readFileSync(0,"utf8").split(/\r?\n/),k=Number(k0),st=[];for(const c of s){if(st.length&&st[st.length-1][0]===c){st[st.length-1][1]++;if(st[st.length-1][1]===k)st.pop();}else st.push([c,1]);}console.log(st.map(x=>x[0].repeat(x[1])).join(""));