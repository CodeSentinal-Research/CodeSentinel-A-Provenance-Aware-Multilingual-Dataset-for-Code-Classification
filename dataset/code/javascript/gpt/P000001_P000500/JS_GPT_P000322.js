// Detect Capital
const fs=require("fs");
const w=fs.readFileSync(0,"utf8").trim();console.log(w===w.toUpperCase()||w===w.toLowerCase()||/^[A-Z][a-z]*$/.test(w)?"Yes":"No");