def is_harshad(n: int) -> bool:
    if n <= 0:
        return False
    sum_d = sum(int(d) for d in str(n))
    return n % sum_d == 0

if __name__ == '__main__':
    n = int(input())
    print("YES" if is_harshad(n) else "NO")