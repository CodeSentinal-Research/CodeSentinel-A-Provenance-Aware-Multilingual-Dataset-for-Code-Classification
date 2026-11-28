# problem title : Add Bold Tag in String
# Mark every interval covered by a dictionary word, then wrap each covered run once.
s=input(); words=input().split(); mark=[False]*len(s)
for w in words:
    start=0
    while True:
        i=s.find(w,start)
        if i<0:break
        for j in range(i,i+len(w)):mark[j]=True
        start=i+1
out='';i=0
while i<len(s):
    if mark[i]:
        j=i
        while j<len(s) and mark[j]:j+=1
        out+='<b>'+s[i:j]+'</b>';i=j
    else:out+=s[i];i+=1
print(out)
