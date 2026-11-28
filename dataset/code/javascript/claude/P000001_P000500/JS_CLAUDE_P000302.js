const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const s=lines[0].trim();const ws=new Set(lines[1].trim().split(' '));
const n=s.length;const dp=new Array(n+1).fill(false);dp[0]=true;
for(let i=1;i<=n;i++)for(let j=0;j<i;j++)if(dp[j]&&ws.has(s.slice(j,i))){dp[i]=true;break;}
console.log(dp[n]?'Yes':'No');
