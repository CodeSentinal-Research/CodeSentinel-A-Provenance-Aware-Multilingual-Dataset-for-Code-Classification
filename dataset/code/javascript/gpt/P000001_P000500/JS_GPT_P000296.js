// Integer to Roman
const fs=require("fs");
let n=Number(fs.readFileSync(0,"utf8").trim()),out="";for(const [v,r] of [[1000,"M"],[900,"CM"],[500,"D"],[400,"CD"],[100,"C"],[90,"XC"],[50,"L"],[40,"XL"],[10,"X"],[9,"IX"],[5,"V"],[4,"IV"],[1,"I"]])while(n>=v){out+=r;n-=v;}console.log(out);