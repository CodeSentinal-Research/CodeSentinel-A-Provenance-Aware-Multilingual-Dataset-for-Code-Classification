const n=BigInt(require('fs').readFileSync('/dev/stdin','utf8').trim());let lo=0n,hi=n;while(lo<hi){const m=(lo+hi+1n)/2n;if(m*m<=n)lo=m;else hi=m-1n;}console.log(lo.toString());
