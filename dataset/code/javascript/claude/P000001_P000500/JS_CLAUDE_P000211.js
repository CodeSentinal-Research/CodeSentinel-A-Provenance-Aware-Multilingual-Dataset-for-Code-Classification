const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=parseInt(lines[0]);
const a=lines[1].trim().split(' ').map(Number).sort((x,y)=>x-y);
const opt1=BigInt(a[n-1])*BigInt(a[n-2])*BigInt(a[n-3]);
const opt2=BigInt(a[0])*BigInt(a[1])*BigInt(a[n-1]);
console.log(String(opt1>opt2?opt1:opt2));
