// Letter Combinations of a Phone Number
const fs=require("fs");
const d=fs.readFileSync(0,"utf8").trim(),map=["","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"],out=[];if(!d){console.log("");process.exit();}function go(i,s){if(i===d.length){out.push(s);return;}for(const c of map[Number(d[i])])go(i+1,s+c);}go(0,"");console.log(out.join("\n"));