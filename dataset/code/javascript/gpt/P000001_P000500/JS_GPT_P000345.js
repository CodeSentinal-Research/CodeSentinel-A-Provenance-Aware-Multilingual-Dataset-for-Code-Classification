// Check Whether Two Strings Contain Same Characters
const fs=require("fs");
const [a,b]=fs.readFileSync(0,"utf8").split(/\r?\n/);const A=new Set(a),B=new Set(b);console.log(A.size===B.size&&[...A].every(c=>B.has(c))?"Yes":"No");