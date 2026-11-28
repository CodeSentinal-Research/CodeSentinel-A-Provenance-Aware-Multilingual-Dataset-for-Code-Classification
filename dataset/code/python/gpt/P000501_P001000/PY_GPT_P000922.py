# problem title : Sum of Digits in a Range
# Solve the stated task using standard input and standard output.
def sum_digits_up_to(n: int) -> int:
    if n <= 0:
        return 0
    s = str(n)
    d = len(s)
    if d == 1:
        return n * (n + 1) // 2
    
    first = int(s[0])
    rem = int(s[1:]) if s[1:] else 0
    p = 10 ** (d - 1)
    
    ans = first * 45 * (d - 1) * (p // 10)
    ans += (first * (first - 1) // 2) * p
    ans += first * (rem + 1)
    ans += sum_digits_up_to(rem)
    return ans

def sum_digits_range(l: int, r: int) -> int:
    return sum_digits_up_to(r) - sum_digits_up_to(l - 1)

if __name__ == '__main__':
    l, r = map(int, input().split())
    print(sum_digits_range(l, r))
