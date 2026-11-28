def is_automorphic(n: int) -> bool:
    sq = n * n
    return str(sq).endswith(str(n))

if __name__ == '__main__':
    n = int(input())
    print("YES" if is_automorphic(n) else "NO")