# problem title : Keyboard Row
# A word fits one keyboard row when all its letters belong to the same row set.
words=input().split(); rows=[set('qwertyuiop'),set('asdfghjkl'),set('zxcvbnm')]; out=[]
for w in words:
    x=set(w.lower())
    if any(x<=r for r in rows):out.append(w)
print(*out)
