
s=input().strip()
map_={'2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}
res=[''] if s else []
for c in s: res=[prev+l for prev in res for l in map_.get(c,'')]
for r in res: print(r)
