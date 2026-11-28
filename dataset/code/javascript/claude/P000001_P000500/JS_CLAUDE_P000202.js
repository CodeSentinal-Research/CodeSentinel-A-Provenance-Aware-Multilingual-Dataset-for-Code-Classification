const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=parseInt(lines[0]);
const nums=lines[1].trim().split(' ').map(Number);
const s=new Set(nums);
let best=0;
for(const x of s){
    if(!s.has(x-1)){
        let cur=1;
        while(s.has(x+cur)) cur++;
        best=Math.max(best,cur);
    }
}
console.log(best);
