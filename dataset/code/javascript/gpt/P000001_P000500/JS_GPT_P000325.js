// Longest Uncommon Subsequence
const fs=require("fs");
const [a,b]=fs.readFileSync(0,"utf8").split(/\r?\n/);console.log(a===b?-1:Math.max(a.length,b.length));