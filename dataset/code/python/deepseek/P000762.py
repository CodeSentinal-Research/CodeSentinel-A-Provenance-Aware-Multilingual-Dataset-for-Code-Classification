Here is a python solution using recursion:

def is_match(s: str, p: str) -> bool:
    if p == "":
        return s == p
    if p.count("*") > 0:
        for i in range(len(p)):
            if p[i] != "*" and p[i] != s[i]:
                return False
        return is_match(s[i+1:], p)
    if p.count("?") > 0:
        return is_match(s[1:], p[1:])
    if p[0] == s[0] or p[0] == "?":
        return is_match(s[1:], p[1:])
    return False

def main():
    s = input("Enter the string: ")
    p = input("Enter the pattern: ")
    print(is_match(s, p))

if __name__ == "__main__":
    main()

In this code, we use recursion to solve the problem. The function `is_match` recursively checks if the given pattern `p` matches the given string `s`. If the pattern is empty (i.e., the end of the pattern), it returns whether the string is also empty. If the pattern contains a wildcard ('*'), it checks all characters in the string against the pattern. If the pattern contains a question mark ('?'), it simply checks the next character in the string against the pattern. If the first character of the pattern matches the first character of the string, it recursively checks the rest of the string and pattern.