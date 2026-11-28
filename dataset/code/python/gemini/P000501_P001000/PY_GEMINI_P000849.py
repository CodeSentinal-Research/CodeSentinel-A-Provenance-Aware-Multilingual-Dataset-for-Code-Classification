def is_even(n: int) -> bool:
    return (n & 1) == 0

if __name__ == '__main__':
    n = int(input())
    print("Even" if is_even(n) else "Odd")