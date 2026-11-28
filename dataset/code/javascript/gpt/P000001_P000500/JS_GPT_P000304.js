// Simplify Path
const fs=require("fs");
const path=fs.readFileSync(0,"utf8").trim(),st=[];for(const x of path.split("/")){if(!x||x===".")continue;if(x==="..")st.pop();else st.push(x);}console.log("/"+st.join("/"));