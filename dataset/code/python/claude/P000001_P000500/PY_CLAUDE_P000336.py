
def check(a,b):
    i,j=0,len(a)-1
    while i<j and a[i]==b[j]: i+=1;j-=1
    mid=a[i:j+1];return mid==mid[::-1] or (lambda m: m==m[::-1])(b[i:j+1])
a,b=input().split()
print('Yes' if check(a,b) or check(b,a) else 'No')
