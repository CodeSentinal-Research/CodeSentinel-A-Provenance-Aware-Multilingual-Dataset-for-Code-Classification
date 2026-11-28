// Reverse String II
const fs=require("fs");
const [s,k0]=fs.readFileSync(0,"utf8").split(/\r?\n/),k=Number(k0),a=[...s];for(let i=0;i<a.length;i+=2*k){let l=i,r=Math.min(i+k,a.length)-1;while(l<r)[a[l++],a[r--]]=[a[r],a[l]];}console.log(a.join(""));