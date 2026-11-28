const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(Number);const goal=+l[2];
const cnt=new Map([[0,1]]);let s=0,ans=0;
for(const v of a){s+=v;ans+=(cnt.get(s-goal)||0);cnt.set(s,(cnt.get(s)||0)+1);}console.log(ans);
