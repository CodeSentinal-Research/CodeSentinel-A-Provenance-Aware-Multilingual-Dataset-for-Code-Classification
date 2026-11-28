
s=input().strip().lower()
vowels=set('aeiou')
n=len(s)
a=sum(1 for c in s[:n//2] if c in vowels)
b=sum(1 for c in s[n//2:] if c in vowels)
print('Yes' if a==b else 'No')
