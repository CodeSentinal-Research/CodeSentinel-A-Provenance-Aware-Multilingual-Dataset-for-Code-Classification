# problem title : Reverse Vowels of a String
# Collect vowels from both ends and swap them in place.
s=list(input()); v=set('aeiouAEIOU'); i,j=0,len(s)-1
while i<j:
    while i<j and s[i] not in v:i+=1
    while i<j and s[j] not in v:j-=1
    s[i],s[j]=s[j],s[i]; i+=1;j-=1
print(''.join(s))
