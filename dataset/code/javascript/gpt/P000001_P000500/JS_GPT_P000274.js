// Implement strStr
const fs=require("fs");
const [h,n]=fs.readFileSync(0,"utf8").split(/\r?\n/);
let ans=-1;if(n.length===0)ans=0;else for(let i=0;i+n.length<=h.length;i++){let j=0;while(j<n.length&&h[i+j]===n[j])j++;if(j===n.length){ans=i;break;}}
console.log(ans);