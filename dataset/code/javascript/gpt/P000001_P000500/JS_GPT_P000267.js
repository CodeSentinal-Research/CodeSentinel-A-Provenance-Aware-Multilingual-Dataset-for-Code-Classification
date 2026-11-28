// Replace a Character with Another
const fs=require("fs");
const [s,a,b]=fs.readFileSync(0,"utf8").split(/\r?\n/);
console.log([...(s||"")].map(c=>c===a?b:c).join(""));