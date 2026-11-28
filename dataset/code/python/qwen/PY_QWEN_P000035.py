n = int(input())
if n <= 1:
    print("Not Perfect")
else:
    s = 1
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            s += i
            if i != n // i:
                s += n // i
    if s == n:
        print("Perfect")
    else:
        print("Not Perfect")
