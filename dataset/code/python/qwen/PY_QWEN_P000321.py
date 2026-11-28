words = input().split()
rows = [set("qwertyuiop"), set("asdfghjkl"), set("zxcvbnm")]
res = []
for w in words:
    lw = w.lower()
    for r in rows:
        if all(ch in r for ch in lw):
            res.append(w)
            break
print(" ".join(res))
