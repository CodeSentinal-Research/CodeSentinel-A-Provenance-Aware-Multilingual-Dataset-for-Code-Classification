const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=parseInt(lines[0]);
const a=lines[1].trim().split(' ').map(Number);
let e1=0,e2=1,c1=0,c2=0;
for(const x of a){
    if(x===e1) c1++;
    else if(x===e2) c2++;
    else if(c1===0){e1=x;c1=1;}
    else if(c2===0){e2=x;c2=1;}
    else{c1--;c2--;}
}
c1=c2=0;
for(const x of a){if(x===e1)c1++;else if(x===e2)c2++;}
const res=[];
if(c1>Math.floor(n/3)) res.push(e1);
if(c2>Math.floor(n/3)) res.push(e2);
console.log(res.join(' '));
