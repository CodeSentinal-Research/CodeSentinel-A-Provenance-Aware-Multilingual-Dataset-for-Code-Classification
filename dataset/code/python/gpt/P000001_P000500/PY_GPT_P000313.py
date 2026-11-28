# problem title : Valid Number
# A small finite-state scan validates sign, digits, decimal point, and exponent rules.
s=input().strip(); i=0
if i<len(s) and s[i] in '+-': i+=1
seen_digit=False; seen_dot=False
while i<len(s) and s[i].isdigit(): seen_digit=True;i+=1
if i<len(s) and s[i]=='.':
    seen_dot=True;i+=1
    while i<len(s) and s[i].isdigit(): seen_digit=True;i+=1
if i<len(s) and s in ('e','E') and seen_digit:
    i+=1
    if i<len(s) and s[i] in '+-':i+=1
    e=i
    while i<len(s) and s[i].isdigit():i+=1
    seen_digit=seen_digit and i>e
print("Valid" if seen_digit and i==len(s) else "Invalid")
