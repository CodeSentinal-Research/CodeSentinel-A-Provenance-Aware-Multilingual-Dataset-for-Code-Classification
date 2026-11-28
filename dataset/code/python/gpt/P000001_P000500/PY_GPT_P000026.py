# problem title : Check Palindrome Number
n = int(input())
s = str(abs(n))
print("Palindrome" if s == s[::-1] else "Not Palindrome")
