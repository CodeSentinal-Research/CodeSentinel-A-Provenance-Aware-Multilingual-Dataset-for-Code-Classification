
line1=input();line2=input()
s=line1.strip();words=set(line2.strip().split())
res=[]
def bt(start,path):
    if start==len(s): res.append(' '.join(path));return
    for end in range(start+1,len(s)+1):
        if s[start:end] in words: bt(end,path+[s[start:end]])
bt(0,[])
print('\n'.join(res))
