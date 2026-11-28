
digits=input()
if not digits: print('');exit()
keys={'2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}
res=['']
for d in digits:
    res=[x+c for x in res for c in keys[d]]
print(*res)
