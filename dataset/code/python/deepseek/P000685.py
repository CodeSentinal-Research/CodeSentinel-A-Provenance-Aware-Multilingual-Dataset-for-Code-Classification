def is_palindrome(s: str) -> bool:
    if len(s) <= 1:
        return True
    elif s[0] != s[-1]:
        return False
    else:
        return is_palindrome(s[1:-1])

def main():
    s = input()
    result = is_palindrome(s)
    print(result)

if __name__ == "__main__":
    main()