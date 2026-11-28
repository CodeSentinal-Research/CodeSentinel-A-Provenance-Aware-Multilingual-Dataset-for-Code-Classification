// Excel Sheet Column Title
const fs=require("fs");
let n=Number(fs.readFileSync(0,"utf8").trim()),out="";while(n){n--;out=String.fromCharCode(65+n%26)+out;n=Math.floor(n/26);}console.log(out);