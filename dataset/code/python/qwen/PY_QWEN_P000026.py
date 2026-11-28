n = input().strip()
if n[0] == '-':
    print("Not Palindrome")
else:
    if n == n[::-1]:
        print("Palindrome")
    else:
        print("Not Palindrome")
