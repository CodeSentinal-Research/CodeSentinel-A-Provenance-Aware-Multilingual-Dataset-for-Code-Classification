const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const[r,c]=l[0].split(' ').map(Number);
let common=null;
for(let i=0;i<r;i++){const s=new Set(l[i+1].split(' ').map(Number));if(!common)common=s;else for(const x of common)if(!s.has(x))common.delete(x);}
console.log([...common].sort((a,b)=>a-b).join(' '));
