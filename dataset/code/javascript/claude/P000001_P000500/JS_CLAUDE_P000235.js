const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const[r,c]=l[0].split(' ').map(Number);const res=[];
for(let i=0;i<r;i++){const row=l[i+1].split(' ').map(Number);res.push(...(i%2===0?row:[...row].reverse()));}
console.log(res.join(' '));
