# problem title : Count Frequency of Each Character
# A dictionary preserves the frequency of each character in first-seen order.
s=input(); f={}
for ch in s:f[ch]=f.get(ch,0)+1
print(*[f"{k}:{v}" for k,v in f.items()])
