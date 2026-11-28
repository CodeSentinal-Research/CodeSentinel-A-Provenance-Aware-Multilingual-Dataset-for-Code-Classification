def mod_add(a: int, b: int, m: int) -> int:
    return ((a % m) + (b % m)) % m

if __name__ == '__main__':
    a, b, m = map(int, input().split())
    print(mod_add(a, b, m))