// Student Attendance Record
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").trim();let a=0,l=0;for(const c of s){if(c==="A")a++;if(c==="L")l++;else l=0;if(a>=2||l>=3){console.log("No");process.exit();}}console.log("Yes");