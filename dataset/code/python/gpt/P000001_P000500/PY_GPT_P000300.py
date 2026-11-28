# problem title : Letter Combinations of a Phone Number
# DFS expands each phone digit using its corresponding keypad letters.
d=input().strip(); mp={'2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}; out=[]
def go(i,s):
    if i==len(d): out.append(s); return
    for ch in mp[d[i]]: go(i+1,s+ch)
if d: go(0,'')
print(*out,sep='\n')
