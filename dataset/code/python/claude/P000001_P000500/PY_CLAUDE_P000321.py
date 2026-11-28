
n=int(input())
rows=['qwertyuiop','asdfghjkl','zxcvbnm']
for _ in range(n):
    w=input().strip()
    wl=w.lower()
    if any(all(c in r for c in wl) for r in rows): print(w)
