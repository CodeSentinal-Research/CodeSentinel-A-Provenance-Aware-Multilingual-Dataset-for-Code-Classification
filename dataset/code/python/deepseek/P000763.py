def isMatch(s: str, p: str) -> bool:
    if not p: return not s

    first_match = bool(s) and (p[0] == s[0] or p[0] == '.')

    if len(p) >= 2 and p[1] == '*':
        return isMatch(s, p[2:]) or (first_match and isMatch(s[1:], p))
    if first_match:
        return isMatch(s[1:], p)

    return False

def main():
    s = input("Enter string s: ")
    p = input("Enter pattern p: ")
    print(isMatch(s, p))

if __name__ == "__main__":
    main()