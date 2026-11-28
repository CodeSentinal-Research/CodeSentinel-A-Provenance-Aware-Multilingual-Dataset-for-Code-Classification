const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=+l[0];const a=l[1].split(' ').map(BigInt);const MOD=1000000007n;
const pre=new Array(n+1).fill(0n);for(let i=0;i<n;i++)pre[i+1]=(pre[i]+a[i])%MOD;
const pp=new Array(n+2).fill(0n);for(let i=0;i<=n;i++)pp[i+1]=(pp[i]+pre[i+1])%MOD;
const left=new Array(n),right=new Array(n);const stk=[];
for(let i=0;i<n;i++){while(stk.length&&a[stk[stk.length-1]]>=a[i])stk.pop();left[i]=stk.length?stk[stk.length-1]:-1;stk.push(i);}
stk.length=0;for(let i=n-1;i>=0;i--){while(stk.length&&a[stk[stk.length-1]]>a[i])stk.pop();right[i]=stk.length?stk[stk.length-1]:n;stk.push(i);}
let ans=0n;
for(let i=0;i<n;i++){const L=left[i]+1,R=right[i]-1;const cl=BigInt(i-L+1),cr=BigInt(R-i);
const tot=((pp[R+2]-pp[i+1]+MOD)%MOD*cl%MOD-(pp[i+1]-pp[L]+MOD)%MOD*cr%MOD+2n*MOD)%MOD;
ans=(ans+a[i]%MOD*tot)%MOD;}console.log(ans.toString());
