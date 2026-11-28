// Shortest Way to Form String
const fs=require("fs");
const [source,target]=fs.readFileSync(0,"utf8").split(/\r?\n/);let count=target.length?1:0,i=0;while(i<target.length){const before=i;for(let j=0;j<source.length&&i<target.length;j++)if(source[j]===target[i])i++;if(i===before){console.log(-1);process.exit();}if(i<target.length)count++;}console.log(count);