// Check if String is Subsequence
const fs=require("fs");
const [a,b]=fs.readFileSync(0,"utf8").split(/\r?\n/);let i=0;for(const c of b)if(i<a.length&&a[i]===c)i++;
console.log(i===a.length?"Yes":"No");