def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def coprime(a, b):
    return gcd(a, b) == 1

def count_coprime(n, l, r):
    count = 0
    for i in range(l, r+1):
        if coprime(i, n):
            count += 1
    return count

if __name__ == "__main__":
    n = int(input())
    l = int(input())
    r = int(input())
    print(count_coprime(n, l, r))

This Python code first defines a function `gcd(a, b)` that calculates the greatest common divisor (gcd) of two numbers. It then defines a function `coprime(a, b)` that checks if two numbers are coprime (i.e., they have no common divisor other than 1). Finally, it defines the main function `count_coprime(n, l, r)` that counts the numbers coprime with `n` in the range `[l, r]`. 

The input handling is done in the main function, where `n`, `l`, and `r` are read from standard input. The count of numbers coprime with `n` in the range `[l, r]` is then printed out.