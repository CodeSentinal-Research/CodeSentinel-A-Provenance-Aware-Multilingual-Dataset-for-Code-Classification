# problem title : Check if String is Subsequence
# Two pointers test whether every character of S1 appears in order inside S2.
a=input(); b=input(); i=0
for ch in b:
    if i<len(a) and a[i]==ch:i+=1
print("Yes" if i==len(a) else "No")
