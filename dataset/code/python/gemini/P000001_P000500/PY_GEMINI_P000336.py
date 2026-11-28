import sys

def check_palindrome_formation(a: str, b: str) -> bool:
    def is_palindrome(s, i, j):
        return s[i:j+1] == s[i:j+1][::-1]

    def check(s1, s2):
        i, j = 0, len(s1) - 1
        while i < j and s1[i] == s2[j]:
            i += 1
            j -= 1
        return is_palindrome(s1, i, j) or is_palindrome(s2, i, j)

    return check(a, b) or check(b, a)

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        print("Yes" if check_palindrome_formation(lines[0], lines[1]) else "No")

if __name__ == '__main__':
    main()