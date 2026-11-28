
s=input().strip();m=int(input());dic=set(input().strip() for _ in range(m))

results=[]
def solve(idx, current):
    if idx==len(s): results.append(' | '.join(current));return
    for end in range(idx+1,len(s)+1):
        word=s[idx:end]
        if word in dic: solve(end, current+[word])
solve(0,[])
for r in results: print(r)
