n = int(input())
res = []
while n > 0:
    n -= 1
    res.append(chr(n % 26 + ord('A')))
    n //= 26
print("".join(res[::-1]))
