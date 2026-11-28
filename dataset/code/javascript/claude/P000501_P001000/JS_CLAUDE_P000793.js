const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);const k=+l[2];
const cnt=new Map([[0,1]]);let odds=0,ans=0;
for(const v of a){odds+=v%2;ans+=(cnt.get(odds-k)||0);cnt.set(odds,(cnt.get(odds)||0)+1);}console.log(ans);
