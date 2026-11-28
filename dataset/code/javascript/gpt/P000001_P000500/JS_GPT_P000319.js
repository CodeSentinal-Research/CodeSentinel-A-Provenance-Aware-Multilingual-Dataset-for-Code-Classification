// One Edit Distance
const fs=require("fs");
const [a,b]=fs.readFileSync(0,"utf8").split(/\r?\n/);if(Math.abs(a.length-b.length)>1){console.log("No");process.exit();}let i=0,j=0,e=0;while(i<a.length&&j<b.length){if(a[i]===b[j]){i++;j++;continue;}if(++e>1)break;if(a.length>b.length)i++;else if(b.length>a.length)j++;else{i++;j++;}}e+=a.length-i+b.length-j;console.log(e===1?"Yes":"No");