# problem title : Split Two Strings to Make Palindrome
# A palindrome can be formed by taking a prefix from one string and suffix from the other.
a=input();b=input()
def ok(x,y):
    i,j=0,len(y)-1
    while i<j and x[i]==y[j]:i+=1;j-=1
    z=x[i:j+1]; return z==z[::-1]
print("Yes" if ok(a,b) or ok(b,a) else "No")
