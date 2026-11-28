# problem title : Check if Word Equals Summation of Two Words
# Each word is interpreted as a base-10 number formed by a=1, b=2, and so on.
a,b,t=input(),input(),input()
def value(w):
    return int(''.join(str(ord(c)-96) for c in w))
print("Yes" if value(a)+value(b)==value(t) else "No")
