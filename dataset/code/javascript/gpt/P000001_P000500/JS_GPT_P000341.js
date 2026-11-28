// Check if Word Equals Summation of Two Words
const fs=require("fs");
const [a,b,t]=fs.readFileSync(0,"utf8").split(/\r?\n/);const val=s=>[...s].reduce((n,c)=>n*10+c.charCodeAt(0)-97,0);console.log(val(a)+val(b)===val(t)?"Yes":"No");