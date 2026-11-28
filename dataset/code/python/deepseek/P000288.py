def valid_palindrome(S):
    def is_valid_palindrome(s, i):
        return s == s[::-1][:i] + s[i:]

    for i in range(len(S)):
        if is_valid_palindrome(S, i):
            return "Yes"
    return "No"

def main():
    S = input()
    print(valid_palindrome(S))

if __name__ == "__main__":
    main()