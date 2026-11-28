// Check if String is Rotation of Another
const fs=require("fs");
const [a,b]=fs.readFileSync(0,"utf8").split(/\r?\n/);
console.log(a.length===b.length&&(a+a).includes(b)?"Yes":"No");