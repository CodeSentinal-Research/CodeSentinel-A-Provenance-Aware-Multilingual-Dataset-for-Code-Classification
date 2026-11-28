# problem title : Valid Word Abbreviation
# Consume abbreviation digits as a positive skip count; leading zeroes are forbidden.
w=input(); ab=input(); i=j=0;ok=True
while j<len(ab):
    if ab[j].isdigit():
        if ab[j]=='0':ok=False;break
        num=0
        while j<len(ab) and ab[j].isdigit():num=num*10+int(ab[j]);j+=1
        i+=num
    else:
        if i>=len(w) or w[i]!=ab[j]:ok=False;break
        i+=1;j+=1
print("Yes" if ok and i==len(w) else "No")
