import sys

def halves_are_alike(s: str) -> bool:
    vowels = set("aeiouAEIOU")
    # Calculate midpoint to prevent potential overflow
    mid = len(s) // 2
    c1 = sum(1 for c in s[:mid] if c in vowels)
    c2 = sum(1 for c in s[mid:] if c in vowels)
    return c1 == c2

def main():
    lines = sys.stdin.read().split()
    if lines:
        print("Yes" if halves_are_alike(lines[0]) else "No")

if __name__ == '__main__':
    main()