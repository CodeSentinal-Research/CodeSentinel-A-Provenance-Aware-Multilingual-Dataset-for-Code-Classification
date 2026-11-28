// Reverse Only Letters
const fs=require("fs");
const a=[...fs.readFileSync(0,"utf8").replace(/\r?\n$/,"")];const letter=c=>/[A-Za-z]/.test(c);let l=0,r=a.length-1;
while(l<r){if(!letter(a[l])){l++;continue;}if(!letter(a[r])){r--;continue;}[a[l],a[r]]=[a[r],a[l]];l++;r--;}console.log(a.join(""));