# problem title : Product of Last K Numbers
# Prefix products make each getProduct query O(1); zero resets the useful prefix.
import sys
lines=sys.stdin.read().strip().splitlines(); pref=[1]; out=[]
for line in lines:
    p=line.split();
    if not p: continue
    if p[0].lower()=="add":
        x=int(p[1]); pref=[1] if x==0 else pref+[pref[-1]*x]
    elif p[0].lower() in ("getproduct","getProduct"):
        k=int(p[1]); out.append(str(pref[-1]//pref[-1-k]) if k<len(pref) else '0')
print('\n'.join(out))
