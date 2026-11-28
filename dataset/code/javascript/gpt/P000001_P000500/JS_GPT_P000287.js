// Reverse Vowels of a String
const fs=require("fs");
const a=[...fs.readFileSync(0,"utf8").replace(/\r?\n$/,"")],v=c=>"aeiouAEIOU".includes(c);let l=0,r=a.length-1;
while(l<r){while(l<r&&!v(a[l]))l++;while(l<r&&!v(a[r]))r--;[a[l],a[r]]=[a[r],a[l]];l++;r--;}console.log(a.join(""));